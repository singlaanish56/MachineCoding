### Models 

[Problem Statement](https://workat.tech/machine-coding/practice/design-parking-lot-qm6hwq4wkhp8)

Vehicle
-type
-registration
-color
+getters
+setters

Car, Bike , Truck Inherits Vehicle

Slot
-slotid
-slotNumber
-floorNumber
-slotType
-Vehicle
-isOccupied

ParkingFloor
-floorId
-floorNumber
-map vehicle, vector Slot* empty
-map vehicle, vector Slot* occupied

ParkingLot
-parkingID
-vector Floor* floors

ParkingStrategy
-SimpleParkingStrategy, Picks the first floor and the first available slot

