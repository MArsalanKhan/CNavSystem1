

#ifndef CROUTE_H_
#define CROUTE_H_
#include "CPoiDatabase.h"

#include "CPOI.h"
#include <iostream>
#include <string>

class CWaypoint;

class CRoute {

private:
    CWaypoint* m_pWaypoint;   // Solution "a": (CWaypoint* m_pWaypoint; is an aggregation relationship because the whole object uses a pointer to address
    //the "part" object. The memory for the part is provided by somebody else(other function)).
    // while (CPOI** m_pPoi; is an association relationship).The objects use a pointer to address the other object.//


    unsigned int m_maxWp;
    unsigned int m_nextWp;
    CPOI** m_pPoi;   // Agreegation
    unsigned int m_maxPoi;
    unsigned int m_nextPoi;
    CPoiDatabase* m_pPoiDatabase;

public:
    CRoute(unsigned int maxWp=0, unsigned int maxPoi=0);  // Initial values are given to the constructor //

    CRoute(CRoute const&origin);

    //CRoute();

    ~CRoute();

    void connectToPoiDatabase(CPoiDatabase* pPoiDB);

    // Solution "b": (The idea behind the method is that we have to connect the point of interest database to CRoute Function and for this we have
    //to declare pointer variable m_pPoiDB in this class so that we can have access to all POIs we have stored in the array block. We can get the value
    // of the respective POI by having pointer address of it. The value for the parameter "pPoiDB" will be provided by CPOI Database in which there are
    // many Point of Interests//

    void addWaypoint(CWaypoint const& wp);

    void addPoi(string namePoi);   //Type 'string' could not be resolved.

    double getDistanceNextPoi(CWaypoint const& wp, CPOI& poi);

    void print();
};

#endif /* CROUTE_H_ */
