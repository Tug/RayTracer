#include "stdafx.h"

#include "Parallelepiped.h"

Parallelepiped::Parallelepiped(P3 & A, P3 & B, P3 & C, P3 & D) : Polyhedron() {
	P3 AB = P3(A,B);
	P3 AC = P3(A,C);
	//P3 D = A + (AB ^ AC);
	P3 AD = P3(A,D);
	triangles.push_back(new Triangle(A,B,C));
	triangles.push_back(new Triangle(A+AB+AC,B,C));
	triangles.push_back(new Triangle(A,B,D));
	triangles.push_back(new Triangle(A+AB+AD,B,D));
	triangles.push_back(new Triangle(A,C,D));
	triangles.push_back(new Triangle(A+AC+AD,B,D));
	P3 OPA = A + AB + AC + AD;
	P3 OPB = B - AB + AC + AD;
	P3 OPC = C - AC + AB + AD;
	P3 OPD = D - AD + AB + AC;
	P3 OPAB = P3(OPA,OPB);
	P3 OPAC = P3(OPA,OPC);
	P3 OPAD = P3(OPA,OPD);
	triangles.push_back(new Triangle(OPA,OPB,OPC));
	triangles.push_back(new Triangle(OPA+OPAB+OPAC,OPB,OPC));
	triangles.push_back(new Triangle(OPA,OPB,OPD));
	triangles.push_back(new Triangle(OPA+OPAB+OPAD,OPB,OPD));
	triangles.push_back(new Triangle(OPA,OPC,OPD));
	triangles.push_back(new Triangle(OPA+OPAC+OPAD,OPB,OPD));
}

Parallelepiped::Parallelepiped(Parallelepiped * parallelepiped) : Polyhedron() {
}

Parallelepiped::~Parallelepiped() {
}

