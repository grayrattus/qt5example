#include "VehicleRepository.h"
#include "Car.h"
#include "Bicycle.h"
#include "Mope.h"

using namespace std;

VehicleRepository::VehicleRepository() {
	
    this->items.push_back(shared_ptr<Car>(new Car(1000, "EBR 69P3la", 5400, SegmentPtr(new Segment('A')))));
    this->items.push_back(shared_ptr<Car>(new Car(1000, "EL 32SOP", 3400, SegmentPtr(new Segment('B')))));
    this->items.push_back(shared_ptr<Car>(new Car(1000, "EL PP002", 3400, SegmentPtr(new Segment('B')))));
    this->items.push_back(shared_ptr<Car>(new Car(1000, "OKL 673SP", 3400, SegmentPtr(new Segment('B')))));

    this->items.push_back(shared_ptr<Mope>(new Mope(1000, "OKL S03B", 3400)));
    this->items.push_back(shared_ptr<Mope>(new Mope(1000, "OKL 909V", 3400)));
    this->items.push_back(shared_ptr<Mope>(new Mope(1000, "EL 23B0", 2300)));
    this->items.push_back(shared_ptr<Mope>(new Mope(1000, "EBR 32BOP", 2300)));

    this->items.push_back(shared_ptr<Bicycle>(new Bicycle("RAMA13243", 500)));
    this->items.push_back(shared_ptr<Bicycle>(new Bicycle("RAMA1323F", 300)));
    
}

VehicleRepository::VehicleRepository(const VehicleRepository& orig) {
}

VehicleRepository::~VehicleRepository() {
}
