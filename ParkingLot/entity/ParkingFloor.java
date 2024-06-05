package MachineCoding.ParkingLot_Java.entity;

import java.util.List;


public class ParkingFloor{
    List<ParkingSlot> parkingSlots=null;

    public ParkingFloor(List<ParkingSlot> parkingSlots)
    {
        this.parkingSlots = parkingSlots;
    }

    //getters and setters
    public List<ParkingSlot> getParkingSlots() {
        return parkingSlots;
    }

    public void setParkingSlots(List<ParkingSlot> parkingSlots) {
        this.parkingSlots = parkingSlots;
    }
}