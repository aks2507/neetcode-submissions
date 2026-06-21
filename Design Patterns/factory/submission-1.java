interface Vehicle {
    String getType();
}

class Car implements Vehicle {
    @Override
    public String getType() {
        return "Car";
    }
}

class Bike implements Vehicle {
    @Override
    public String getType() {
        return "Bike";
    }
}

class Truck implements Vehicle {
    @Override
    public String getType() {
        return "Truck";
    }
}

abstract class VehicleFactory {
    abstract Vehicle createVehicle();
}

class CarFactory extends VehicleFactory {
    // Write your code here
    @Override
    public Car createVehicle() {
        // Car car = new Car();
        // return car;
        return new Car();
    }
}

class BikeFactory extends VehicleFactory {
    // Write your code here
    @Override
    public Bike createVehicle() {
        // Bike bike = new Bike();
        // return bike;
        return new Bike();
    }
}

class TruckFactory extends VehicleFactory {
    // Write your code here
    @Override
    public Truck createVehicle() {
        // Truck truck = new Truck();
        // return truck;
        return new Truck();
    }
}
