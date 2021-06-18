//System Include Files
#include <iostream>
#include <string>
#include <stdlib.h>

//Own Include Files
#include "CPoiDatabase.h"
#include "CPOI.h"

using namespace std;

//Method Implementations

//Initialize the data(attributes)//

CPoiDatabase::CPoiDatabase() {

	m_noPoi = 0;
//CPOI pointofinterest(t_poi type, string name, string description, double latitude, double longitude);
}

void CPoiDatabase::addPoi(t_poi type, string name, string description,
		double latitude, double longitude) {
	//for (int a = 0; a < 10; a++) {
		m_POI[m_noPoi] = CPOI(type, name, description, latitude, longitude);
		m_noPoi++;

	//}
	//if (m_noPoi>=10)
	//{
	//cout << "Values are out of range " << endl;
	//}

}

//Searching for a POI with the provided name (STEP7)//
CPOI* CPoiDatabase::getPointerToPoi(string name) {
	CPOI* ptrpoi;
	string name_l = "";
	double latitude_l = 0;
	double longitude_l = 0;
	string description_l = "";
	t_poi type_l;

	for (int a = 0; a < 10; a++) {
		m_POI[a].getAllDataByReference(name_l, latitude_l, longitude_l, type_l,
				description_l);
		//if(m_POI[a].getName()==name)
		if (name == name_l) {
			ptrpoi = &m_POI[a];
			return ptrpoi;
		}
	}
	return 0;
}

