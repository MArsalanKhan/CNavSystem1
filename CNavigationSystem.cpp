
//System Include Files
#include<iostream>
#include<string>

//Own Include Files (Navigation System's major components, GPS sensor, Route and a Point of Interest Database)//

#include "CNavigationSystem.h"
#include "CRoute.h"
#include "CPOI.h"
#include "CPoiDatabase.h"
#include "CGPSSensor.h"
#include "CWaypoint.h"
using namespace std;

//Method Implementations

// Member initializer list(Defining number of Waypoints and POIs)  //

CNavigationSystem::CNavigationSystem():m_route(3,3)
{
	//enterRoute();
//m_GPSSensor=CGPSSensor();
//m_route = CRoute(2,3);
//m_PoiDatabase= CPoiDatabase();

}

// Entering POIs and waypoints to the route (STEP4)//
void CNavigationSystem::enterRoute(){

// Implemeting the waypoints and POIS //
CWaypoint WP_Amsterdam("Amsterdam ",52.3142,4.9418);
CWaypoint WP_Wohnung("Nieder-Ramstadter ", 49.859041, 8.674468);
CWaypoint WP_University("Hochschule Darmsatdt ", 49.864740, 8.643225);


m_route.connectToPoiDatabase(&m_PoiDatabase);
m_route.addWaypoint(WP_Amsterdam);
m_route.addWaypoint(WP_Wohnung);
m_route.addWaypoint(WP_University);


m_PoiDatabase.addPoi(RESTAURANT,"KFC"," Best place to eat and drink ",49.854740, 8.643000);
m_PoiDatabase.addPoi(SIGHTSEEING,"Mathiledenhohe"," Best place to discover art ",49.876143, 8.670332);
m_PoiDatabase.addPoi(RESTAURANT,"Mensa HDA"," The best Mensa in the world ",10, 20);

m_route.addPoi("KFC");
m_route.addPoi("Mathiledenhohe");
m_route.addPoi("Mensa HDA");

}

// Printing POIs and waypoints to the route (STEP5)//
void CNavigationSystem::printRoute(){

	m_route.print();

}

// Getting the current position from the GPS sensor and search for the closest Point of Interest (STEP6)//
void CNavigationSystem::printDistanceCurPosNextPoi()
{

CPOI poi;
double Distance;
CWaypoint presentlocation;

cout << "Testing of the GPS Sensor and calculating the distance to the next point of interest " << endl;
presentlocation= m_GPSSensor.getCurrentPosition();


Distance = m_route.getDistanceNextPoi(presentlocation,poi);

cout << "Distance to the next point of interset = " << Distance << endl;
//cout << "Point of Interest " << endl;
//cout << "=================="  << endl;

poi.print();

}

//IMPLEMENTING THE CHECKING OPERATION OF NAVIGATION SYSTEM //
void CNavigationSystem::run()
{

enterRoute();
printRoute();
printDistanceCurPosNextPoi();

}

