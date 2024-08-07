// SingleListTest.cpp 对该单链表的测试代码

#include <iostream>
#include "SingleList.h"

int main(void) {
	SingleList list;

	list.add(0);
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(4);	// 添加已存在元素
	list.remove(0); // 末尾元素
	list.remove(2); // 中间元素
	list.remove(4); // 开头元素
	list.remove(4); // 删除不存在元素
	for (auto temp = list.dummy->next; temp; temp = temp->next)
		std::cout << temp->data << " ";
	std::cout << std::endl;
	/*期望的输出
	4 exists, add failed!
	4 does not exist, remove failed!
	3 1
	Element deleted!
	Element deleted!
	SingleList Destroyed!
	*/
	return 0;
}

