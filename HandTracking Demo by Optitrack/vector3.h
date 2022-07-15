#pragma once
#include <math.h>
using namespace std;

/// <summary>
/// Ư�� ��Ŀ�� ����Ʈ�� ��Ÿ���� ���� ����ϴ� Vector3 Ŭ����.
/// x,y,z point�� ��ǥ�� �������ش�. 
/// </summary>

class Vector3 {

	public:
		Vector3() // �⺻ ������ 
		{
			x = 0;
			y = 0;
			z = 0;
		}

		Vector3(const float x, const float y, const float z) // X,Y,Z ���� �� �� ���� ������ 
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		float GetMagnitude()
		{
			auto magnitude = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
			return magnitude;
		}

		// ���� ������ ���� �̸� �ٸ� ���� ��������� 
		void Set_Vector(Vector3& vector)
		{
			vector.x = this->x;
			vector.y = this->y;
			vector.z = this->z;

		}

		friend Vector3 operator+(const Vector3& a, const Vector3& b)
		{
			float Vx = a.x + b.x;
			float Vy = a.y + b.y;
			float Vz = a.z + b.z;

			return Vector3(Vx, Vy, Vz);
		}

		friend Vector3 operator-(const Vector3& a, const Vector3& b)
		{
			float Vx = a.x - b.x;
			float Vy = a.y - b.y;
			float Vz = a.z - b.z;

			return Vector3(Vx, Vy, Vz);
		}

		friend Vector3 operator*(const Vector3& a, const Vector3& b)
		{
			float Vx = a.x * b.x;
			float Vy = a.y * b.y;
			float Vz = a.z * b.z;

			return Vector3(Vx, Vy, Vz);
		}

		bool operator ==(Vector3 b) {
			if (x == b.x && y == b.y && z == b.z)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		float x;
		float y;
		float z;
};