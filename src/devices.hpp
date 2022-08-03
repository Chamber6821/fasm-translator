#pragma once

#include "../factorio-asm/syntax.hpp"

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
	member(Source, GetStackSize(RegisterSource resource), resource => (U3 G2))
end

module(Spaceport)
	member(Source, SeatForLoad,   (U4 G1))
	member(Source, SeatForUnload, (U4 G2))
	member(Source, SelectedSeat,  (U4 G3))

	member(void, ChooseSeat(RegisterSource id), id => (U4 M1))
end

module(Seat)
	member(Source, Geopoint, (U4 G4))
	member(Source, Capacity, (U4 G5))
	member(Source, Contents, (U4 G6))

	member(void, SetReturnPointForShip(RegisterSource point), point => (U4 M2))
	member(void, SetLogisticRequest(RegisterSource request), request => (U4 M3))
	member(void, UnloadAllResources(), (U4 M4))
end
