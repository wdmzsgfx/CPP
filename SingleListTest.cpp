// SingleListTest.cpp �Ըõ�����Ĳ��Դ���

#include <iostream>
#include "SingleList.h"

int main(void) {
	SingleList list;

	list.add(0);
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(4);	// ����Ѵ���Ԫ��
	list.remove(0); // ĩβԪ��
	list.remove(2); // �м�Ԫ��
	list.remove(4); // ��ͷԪ��
	list.remove(4); // ɾ��������Ԫ��
	for (auto temp = list.dummy->next; temp; temp = temp->next)
		std::cout << temp->data << " ";
	std::cout << std::endl;
	/*���������
	4 exists, add failed!
	4 does not exist, remove failed!
	3 1
	Element deleted!
	Element deleted!
	SingleList Destroyed!
	*/
	return 0;
}

