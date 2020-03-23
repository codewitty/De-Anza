/*
Assume the existence of a Building class. Define a derived class, ApartmentBuilding 
that contains four (4) data members: an integer named numFloors, an integer named unitsPerFloor, a boolean named hasElevator, and a boolean named hasCentralAir. There is a constructor containing parameters for the initialization of the above variables (in the same order as they appear above). There are also two functions: the first, getTotalUnits, accepts no parameters and returns the total number of units in the building; the second, isLuxuryBuilding accepts no parameters and returns true if the building has central air, an elevator and 2 or less units per floor.
*/

class ApartmentBuilding : public Building
{
    private:

    int  numFloors;
    int  unitsPerFloor;
    bool hasElevator;
    bool hasCentralAir;

    public:

    ApartmentBuilding( int nFloors, int uPerFloor, bool hasEVator, bool hasCAir );
    int  getTotalUnits();
    bool isLuxuryBuilding();
};

ApartmentBuilding::ApartmentBuilding( int nFloors, int uPerFloor, bool hasEVator, bool hasCAir )
{
    numFloors     = nFloors;
    unitsPerFloor = uPerFloor;
    hasElevator   = hasEVator;
    hasCentralAir = hasCAir;
}

int ApartmentBuilding::getTotalUnits()
{
    return (numFloors * unitsPerFloor);
}

bool ApartmentBuilding::isLuxuryBuilding()
{
    bool retVal = false;
    if ( (unitsPerFloor <= 2) && hasElevator && hasCentralAir ) {
        retVal = true;
    }
    return retVal;
}
