#pragma once

#include "syntax.hpp"

module(Storage)
	member(Source, Get(int address), (U2 G(address)))
	member(void, Set(int address, RegisterSource value), value => (U2 M(address)))

	member(Source, GetStationResources(), Get(1))
	member(void, SetStationResources(RegisterSource value), Set(1, value))

	member(Source, GetSentResources(), Get(2))
	member(void, SetSentResources(RegisterSource value), Set(2, value))
end

module(Resources)
	member(Source, Requested, (U3 G1))
	member(Source, WhoIsRecipient, "Меня надо релизовать :)")
	
	member(Source, GetStackSize(RegisterSource resource), resource => (U3 G2))
end

module(Cosmoport)
	member(Source, AnyForLoad,   (U4 G1))
	member(Source, AnyForUnload, (U4 G2))
	member(Source, AnyForLaunch, "Меня надо релизовать :)")
	member(Source, SelectedSeat,  (U4 G3))

	member(void, ChooseSeat(RegisterSource id), id => (U4 M1))
end

module(Seat)
	member(Source, Capacity, (U4 G5))
	member(Source, Contents, (U4 G6))

	member(void, SetCource(RegisterSource point), point => (U4 M2))
	member(void, SetLogisticRequest(RegisterSource request), request => (U4 M3))
	member(void, UnloadAllResources(), (U4 M4))
	member(void, Launch(), "Меня надо релизовать :)")
end
