#define _CRT_SECURE_NO_WARNINGS
#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON
#include <cstdio>
#include <vector>

// RapidJson ����� ���� Testbed
// ���⼭�� �ƹ��͵� ���� ������ JSONȭ �� String�� ���� �� , ������ �����ϴ� ������ ��� ����. 
// Step 1. JSON�� �а� ���� ���� document ��ü�� ���� 
// Step 2. Value�� �ϳ� ��������. (array type����)
// Step 3. Document�� ���� �Ҵ��ϱ� ���� allocator ����
// Step 4. �ݺ������� Ư�� ���� �������� AddMember����.  
// Step 5. myArray��� ��value�� allocator�� ���� �־���. 
// Step 6. ���Ϸ� ����.  (�̿�) 

using namespace rapidjson;
using namespace std;

int main(int, char* []) {
	Document document;  // Default template parameter uses UTF8 and MemoryPoolAllocator.
    document.SetObject(); // �� JSON ��ü�� ������ 

    Value myArray(kArrayType); // ���� ���� value ��ü ���� 
    rapidjson::Document::AllocatorType& allocator = document.GetAllocator(); // document ��ü�� ���� �����ϰ� ���ִ� allocator ��ü �༺ 
    for (int i=0; i<5; i++)
    {
        rapidjson::Value objValue;
        objValue.SetInt(i); // value�� ���� ���� 
        //������ �ְ� ���� ��� objValue.AddMember("playername",i, allocator);
        myArray.PushBack(objValue, allocator);//allocator�� ���� ���� �ش� value ������Ʈ�� �־��� 
    }

    document.AddMember("array", myArray, allocator); // ��ť��Ʈ�� ����� �߰����� 


    printf("\nModified JSON with reformatting:\n");
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);
    document.Accept(writer);    // Accept() traverses the DOM and generates Handler events.
    puts(sb.GetString());
    
    return 0;
}