package MachineCoding.ParkingLot.entity;


public class ParkingSlot{
    int floorId;
    int slotId;
    Vehicle vehicle;
    boolean isFree;
    VehicleType vehicleType;

    public ParkingSlot(VehicleType vechicType, boolean isFree, int slotid)
    {
        this.vehicleType = vechicType;
        this.isFree = isFree;
        this.slotId = slotid;
    }

    //getters and setters
    public VehicleType getVehicleType() {
        return vehicleType;
    }

    public void setVehicleType(VehicleType vehicleType) {
        this.vehicleType = vehicleType;
    }

    public int getFloorId() {
        return floorId;
    }

    public void setFloorId(int floorId) {
        this.floorId = floorId;
    }

    public int getSlotId() {
        return slotId;
    }

    public void setSlotId(int slotId) {
        this.slotId = slotId;
    }

    public Vehicle getVehicle() {
        return vehicle;
    }

    public void setVehicle(Vehicle vehicle) {
        this.vehicle = vehicle;
    }

    public boolean isFree() {
        return isFree;
    }

    public void setFree(boolean free) {
        isFree = free;
    }    
}