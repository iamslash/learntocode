// Copyright (C) 2020 by iamslash

// if red light, turnGreen and crossCar or
// if blue light, just crossCar

// 8ms 96.46% 39.9MB 100.00%
// synchronized
class TrafficLight {
	class Signal {
		int greenRoad = 1;
	}
	private final Signal signal = new Signal();

	public TrafficLight() {
	         
	}
    
	public void carArrived(
			int carId,           // ID of the car
			int roadId,          // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
			int direction,       // Direction of the car
			Runnable turnGreen,  // Use turnGreen.run() to turn light to green on current road
			Runnable crossCar    // Use crossCar.run() to make car cross the intersection 
												 ) {
		synchronized(signal) {
			if (signal.greenRoad != roadId) {
				turnGreen.run();
				signal.greenRoad = roadId;
			}
			crossCar.run();
		}
	}
}
