#include "syntax.hpp"
#include "std/math.hpp"
#include "std/foreach.hpp"
#include "std/debug.hpp"
#include "std/fibonacci.hpp"

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

procedure(updateCourceForSelectedShip, (Register geopoint),
	mv(geopoint, Resources::WhoIsRecipient);
	Seat::SetCource(rd(geopoint));
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
		updateCourceForSelectedShip(reg2);

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
		updateCourceForSelectedShip(reg3);

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


procedure(receiveParcels, (Register port, Register reg2, Register reg3, Register reg4),
	while_not (zero, Cosmoport::AnyForLoad,
		mv(port, Cosmoport::AnyForLoad);
		Cosmoport::ChooseSeat(rd(port));

		load(port, reg2, reg3, reg4);
	)
)


procedure(sendParcels, (Register port, Register reg2, Register reg3, Register reg4),
	while_not (zero, Cosmoport::AnyForUnload,
		mv(port, Cosmoport::AnyForUnload);
		Cosmoport::ChooseSeat(rd(port));

		unload(port, reg2, reg3, reg4);
	)
)


LOOP_START
	#define _ALL_REGISTERS DeclareRegister(1), DeclareRegister(2), DeclareRegister(3), DeclareRegister(4)

	receiveParcels(_ALL_REGISTERS);
	sendParcels(_ALL_REGISTERS);
LOOP_END
