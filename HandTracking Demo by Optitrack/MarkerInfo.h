
#pragma once
#include "Unpack_Packet.h"
#include "vector3.h"
#include "math.h"
using namespace std;
/// <summary>
/// Optitrack���� ��Ŀ ������ ���� ��Ŷ �����Ȱ� ����ڰ� ���ϴ� ������ ���·� �������� �Ϸ��� ���� Ŭ����. 
/// Optitrack�� Unpack Marker Description�� �����Ѵ�. 
/// 1. ��Ŀ�� ��ǥ�� ������ 
/// 2. ��Ŀ�� ������ Ŭ�������� ������ ���� (Labeling�� ��)
/// </summary>

class Marker {

	public:
		Vector3 pos; // ��Ŀ�� ��ġ���� 
		int label_index; // ��Ŀ�� �󺧸� �ε��� 
		Vector3 targetPos; // Ư�� ��ġ�� ��Ҵ��� ���� �ʾҴ����� �Ǵ��ϱ� ���� ������ġ. �ӽú��� 

		// ��Ŀ�� ��ġ�� �������ִ� �Լ� 
		void GetMarkerPos(Vector3& pos)
		{
			pos = this->pos;

		}

		// ��Ŀ�� ��ġ���� set ���ִ� �Լ�. unpack packet�� ȣ��ο��� ���������� Set ���ش�.  
		void SetMarkerPos(Vector3& pos) {

			this->pos = pos;
		}

		// Ÿ���� ���� ��Ҵ��� �ȴ������ �Ǵ�����. �ӽ� �Լ�.  
		bool IsCollide()
		{
			Vector3 mag = pos - targetPos;
			if (abs(mag.GetMagnitude() < 0.01f)) 
				return true;

			return false;

		}
};

