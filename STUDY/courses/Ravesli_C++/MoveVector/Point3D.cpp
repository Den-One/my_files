#include <iostream>

#include "Point3D.h"
#include "Vector3D.h"

void Point3D::moveByVector(const Vector3D& v)
{
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
}

void Point3D::print()
{
	std::cout << "Vector( " << m_x << ", " <<
		m_y << ", " << m_z << ")\n";
}
