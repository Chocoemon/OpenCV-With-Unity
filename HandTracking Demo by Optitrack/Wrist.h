///*Summary 
/// - ���� ȸ��������, �밭���� ��ġ �ľ��� ���� ���� Ŭ����
/// - ȸ�������� Quternion�� ���·� ����
/// - �ո��� ��ġ�� Vector3 Type���� ���� 
/// - �̸� ���� Getter, Setter ���� 
///
#pragma once
#include "Vector3.h"

using namespace std;

class Quternion
{
public:

	Quternion()
	{
		qx = 0;
		qy = 0;
		qz = 0;
		qw = 0;
	}


	Quternion(float _qx, float _qy, float _qz, float _qw)
	{
		qx = _qx;
		qy = _qy;
		qz = _qz;
		qw = -qw;
	}

	float qx;
	float qy;
	float qz;
	float qw;
	/*
		private:
			float qx;
			float qy;
			float qz;
			float qw;
			*/


};


class Wrist {

	public:
		Vector3 pos;
		Quternion orientation;

		Wrist()
		{
			
		}


		Wrist(Vector3& pos, Quternion& ori)
		{
			this->pos = pos;
			this->orientation = ori; // ���ο� ���ʹϾ� ���� �Ҵ��� 
		}

		/// <summary>
		/// Set Orientation and position info of it
		/// </summary>
		void SetWristInfo(Vector3& pos, Quternion& orientation)
		{
			this->pos = pos;
			this->orientation = orientation;
			//printf("    pos: [%3.2f,%3.2f,%3.2f]\n", this->pos.x, pos->y, pos->z);
			printf("    ori: [%3.2f,%3.2f,%3.2f,%3.2f]\n", this->orientation.qx, this->orientation.qy, this->orientation.qz, this->orientation.qw);
		}


		/// <summary>
		/// �����͸� �Ѱܹ�����, ���⿡ ���� �Ҵ����� 
		/// </summary>
		void GetWristInfo(Vector3& pos, Quternion& orientation)
		{
			pos = this->pos;
			orientation = this->orientation;
		}


};



