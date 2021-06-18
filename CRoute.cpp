//System include files//
#include <iostream>
#include <string>
#include <cmath>

//Own include files//
#include "CRoute.h"
#include "CWaypoint.h"
#include "CPoiDatabase.h"
#include "CPOI.h"

using namespace std;

CRoute::CRoute(unsigned int maxWp, unsigned int maxPoi) {

	m_maxWp = maxWp;            // Initializing the attributes in constructor //
	m_maxPoi = maxPoi;
	m_pWaypoint = new CWaypoint[m_maxWp];          // Sequential execution
	m_nextWp = 0;
	m_pPoi = new CPOI*[m_maxPoi];
	m_nextPoi = 0;
	m_pPoiDatabase = NULL;

}

//CRoute::CRoute(const CRoute&origin)
//{
//	m_maxWp=origin.m_maxWp;                        // COPY CONSTRUCTOR //
//	m_maxPoi=origin.m_maxPoi;
//	m_pWaypoint=0;
//	m_nextWp=0;
//	m_pPoi=0;
//	m_nextPoi=0;
//	m_pPoiDatabase=NULL;
//
//
//}
void CRoute::addWaypoint(const CWaypoint& wp) {

	if (m_nextWp <= m_maxWp) {
		m_pWaypoint[m_nextWp] = wp;
		++m_nextWp;                     // incrementing the next waypoints //

	} else {
		cout << "ERROR: Cannot add more than   " << m_maxWp << "in a route "
				<< endl;
		cout << "Try creating a new route " << endl;
	}

}

void CRoute::addPoi(string namePoi) {
//calling getpointertopoi function //

	if(m_pPoiDatabase!=0)
		{
		if(m_nextPoi<m_maxPoi)
		{

			m_pPoi[m_nextPoi]=m_pPoiDatabase->getPointerToPoi(namePoi);
			m_nextPoi++;
		}

		else
		{
			cout<<"Array full"<<endl;
		}

		}








}

// This function will tell the distance between nearest possible point of interest //

double CRoute::getDistanceNextPoi(CWaypoint const& wp, CPOI& poi) {

	double mydistance=0;
		double distance=0;
		distance= (*m_pPoi[0]).calculateDistance(wp);
		cout<<"Distance to next POI is "<<distance<<endl;

		for(unsigned int i=1;i<m_nextPoi;i++)
		{
			mydistance=(*m_pPoi[i]).calculateDistance(wp);
			cout<<"Distance found "<<i+1<<" is "<<mydistance<<endl;

			if(mydistance<distance)
			{
				distance=mydistance;
			}
		}

		return distance;

//	// We have to compare the values and calculate the closest distance and check the condition whether it is true/false, we have to implement boolean function//
//	bool exchange = true;
//
//	// Inroducing a local variable //
//	int a = 0;
//
//	//To find the distance between two points, so introducing some variables//
//	double distance[m_nextPoi]; // Distance from one point of interest to next point of interest //
//	double tempdistance[m_nextPoi]; // Distance from one temporary point(it depends on the position of Waypoint & POI) to next point //
//
//	//Initializing some variables:(To calculate the nearest(minimum) distance, we have to initailzie some variables related to POI)//
//	double nearestdist = 0, temp = 0, poi_latitude = 0, poi_longitude = 0;
//	string poi_name, poi_description;
//	t_poi poi_type;
//
//	//For accessing waypoint object //
//	CWaypoint WP_Poi(poi_name, poi_latitude, poi_longitude);
//	m_pWaypoint = (CWaypoint*) &wp;
//
//	//We have to get the POI parameters and calculating the distance with respect to the waypoint we have taken. //
//	for (unsigned int b = 0; b < m_nextPoi; b++) {
//		poi = (*m_pPoi)[b];
//		poi.getAllDataByReference(poi_name, poi_latitude, poi_longitude,
//				poi_type, poi_description);
//		WP_Poi = CWaypoint(poi_name, poi_latitude, poi_longitude);
//
//		// Calculating the distance b/w WP and POI at a particular instant.//
//		distance[b] = m_pWaypoint->calculateDistance(WP_Poi);
//		cout << "Distance to next POI = " << distance[b] << "km" << endl;
//		poi.print();
//	}
//
////Sorting of point of interests //
//
//	for (unsigned int i = 0; i < m_nextPoi; i++) {
//
//		tempdistance[i] = distance[i];
//	}
//
//// Since we have to check condition of sorting we are using while loop //
//
//	while (exchange) {
//		exchange = false;
//		a++;
//		for (unsigned int i = 0; i < m_nextPoi - a; i++) {
//			if (distance[i] > distance[i] + 1) {
//				temp = distance[i];
//				distance[i] = distance[i + 1];
//				distance[i + 1] = temp;
//				exchange = true;
//
//			}
//		}
//	}
//
//	for (unsigned int a = 0; a < m_nextPoi; a++) {
//		if (distance[0] == tempdistance[a]) {
//			poi = (*m_pPoi)[a];
//			poi.getAllDataByReference(poi_name, poi_latitude, poi_longitude,
//					poi_type, poi_description);
//			poi = CPOI(poi_type, poi_name, poi_description, poi_latitude,
//					poi_longitude);
//			break;
//
//		}
//	}
//
//	nearestdist = distance[0];
//	return nearestdist;

}

void CRoute::print() {

	CPOI tempPOI;
	CWaypoint tempWp;
	//cout << "Number of maximum waypoints " << m_maxWp << endl;
	cout << "Our route has " << m_nextWp << " Waypoints and " << m_nextPoi
			<< " Point of interests" << endl;
	cout << "Waypoints" << endl;
	cout << "========" << endl;

	for (unsigned int i = 0; i < m_nextWp; i++) {
		tempWp = m_pWaypoint[i];
		tempWp.print(2);

		//cout << m_pWaypoint->print(2)<< endl;
	}
	cout << "Point of Interest" << endl;
	cout << "========" << endl;

	for (unsigned int j = 0; j < m_nextPoi; j++) {
//		*m_pPoi[j]->print();
		tempPOI = *m_pPoi[j];
		tempPOI.print();
	}
}

CRoute::~CRoute() {
	// Destroying the memory locations  //

	delete[] m_pWaypoint;
	delete[] m_pPoi;
#ifdef SHOWADDRESS
	cout<< "Object is destroyed at " << this << endl;
#endif
}

void CRoute::connectToPoiDatabase(CPoiDatabase* pPoiDB) {
	m_pPoiDatabase = pPoiDB;

}

