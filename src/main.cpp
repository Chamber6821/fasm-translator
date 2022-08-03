#include "../factorio-asm/syntax.hpp"
#include "../factorio-asm/std/math.hpp"
#include "../factorio-asm/std/foreach.hpp"
#include "../factorio-asm/std/debug.hpp"
#include "../factorio-asm/std/fibonacci.hpp"

#include "devices.hpp"


procedure(addToStationcResources, (RegisterSource value, Register stationResources),
	mv(stationResources, Storage::GetStationResources());
	combineAssign(stationResources, value);
	Storage::SetStationResources(rd(stationResources));
)

procedure(addToSentResources, (RegisterSource value, Register sentResources),
	mv(sentResources, Storage::GetSentResources());
	combineAssign(sentResources, value);
	Storage::SetSentResources(rd(sentResources));
)

procedure(convertResultToStacks, (Register result, Register stackSize),
	mv(stackSize, Resources::GetStackSize(rd(result)));
	calcAssign(result, div, rd(stackSize));
	
	if_not (zero, res(mod),
		mvR(1);
		mv(result, res(add));
	)
)

procedure(getRealReqestNegative, (Register result, Register onWay),
	mv(result, Resources::Requested);
	mv(onWay, Storage::GetSentResources());
	
	assignOpposite(result);
	combineAssign(result, rd(onWay));
)

procedure(updateReturnPointForShip, (Register geopoint),
	mv(geopoint, Seat::Geopoint);
	Seat::SetReturnPointForShip(rd(geopoint));
)


procedure(findResourceToSend, (Register result, Register reg1, Register reg2, Register reg3),
	#define request          reg1
	#define stationResources reg2
	#define capacity         reg3

	getRealReqestNegative(request, reg2);

	mv(capacity, Seat::Capacity);

	findResourceToSend_continue:
	foreach(result, request,
		calcAssign(result, mult, rd(capacity));

		mv(stationResources, Storage::GetStationResources());
		combineAssign(stationResources, rd(result));
		if_not (any_negative, rd(stationResources),
			jmp(findResourceToSend_return);
		)
	)

	findResourceToSend_return:
)
#undef capacity
#undef stationResources
#undef request


procedure(load, (Register reg1, Register reg2, Register reg3, Register reg4),
	#define resource reg1

	findResourceToSend(resource, reg2, reg3, reg4);

	critical(
		Seat::SetLogisticRequest(rd(resource));
		updateReturnPointForShip(reg2);

		assignOpposite(resource);
		addToStationcResources(rd(resource), reg2);

		calcAssign(resource, single);
		addToSentResources(rd(resource), reg2);
	)
)
#undef resource


procedure(unload, (Register reg1, Register reg2, Register reg3, Register reg4),
	#define stacks            reg1
	#define resources         reg2
	#define stationResources  reg4

	critical(
		Seat::UnloadAllResources();
		updateReturnPointForShip(reg3);


		mv(stationResources, Storage::GetStationResources());

		mv(resources, Seat::Contents);
		assignOpposite(resources);
		foreach(stacks, resources,
			convertResultToStacks(stacks, reg3);
			combineAssign(stationResources, rd(stacks));
		)

		Storage::SetStationResources(rd(stationResources));
	)
)
#undef stationResources
#undef resources
#undef stacks

PROGRAM_START

	/*#define port       DeclareRegister(1)
	#define resigsters DeclareRegister(1), DeclareRegister(2), DeclareRegister(3), DeclareRegister(4)

	if_not (zero, Spaceport::SeatForLoad,
		mv(port, Spaceport::SeatForLoad);
		Spaceport::ChooseSeat(rd(port));

		load(resigsters);
	)
	
	if_not (zero, Spaceport::SeatForUnload,
		mv(port, Spaceport::SeatForUnload);
		Spaceport::ChooseSeat(rd(port));

		unload(resigsters);
	)

	#define someRegister DeclareRegister(1)
	assert(all_positive, someRegister);*/

	fibonacci(DeclareRegister(1), DeclareRegister(2), DeclareRegister(3));
	exit(0);

PROGRAM_END
