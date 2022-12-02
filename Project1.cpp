#include "AVLTree.h"
#include"Player.h"
#include"Team.h"
#include <iostream>

int main()
{
	AVLTree<int> test1;
	test1.insert(100);
	test1.insert(1000);
	test1.insert(10);
	test1.insert(5);
	test1.insert(1);
	test1.insert(90);
	test1.insert(2000);
	test1.insert(3000);
	test1.insert(4000);
	test1.insert(3);
	int* arr = new int [test1.NodeCount];
	test1.inorder(arr);
	for (int i = 0; i < test1.NodeCount; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl<<endl;
	test1.printTree(test1.root);
	std::cout<< test1.height();
	std::cout << "---------------------------------" << std::endl;
	AVLTree<int>::Node* x = test1.search(3000);
	test1.remove(*x->data);
	test1.printTree(test1.root);
	std::cout << "---------------------------------" << std::endl;
	test1.insert(2); 
	test1.printTree(test1.root);
	std::cout << "---------------------------------" << std::endl;
	AVLTree<int> test2;
	test2.insert(100);
	test2.insert(1000);
	test2.insert(10);
	test2.insert(2000);
	test2.insert(3000);
	test2.printTree(test2.root);
	std::cout << "---------------------------------" << std::endl;
	AVLTree<int> test3;
	test3.insert(100);
	test3.insert(1000);
	test3.insert(10);
	test3.insert(50);
	test3.insert(70);
	test3.printTree(test3.root);
	std::cout << "---------------------------------" << std::endl;
	AVLTree<int> test4;
	test4.insert(100);
	test4.insert(1000);
	test4.insert(10);
	test4.insert(200);
	test4.insert(300);
	test4.printTree(test4.root);
	std::cout << "---------------------------------" << std::endl;
	AVLTree<int> test5 = test1;
	test4.printTree(test5.root);
	std::cout << "---------------------------------" << std::endl;
	AVLTree<int> test6 (test1);
	test4.printTree(test6.root);
	std::cout << "---------------------------------" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	Team t1(1);
	Player p1 = *(new Player(2, t1.getTeamId()));
	AVLTree<Player> test7;
	test7.insert(p1);
	test7.printTree(test7.root);
	std::cout << "---------------------------------" << std::endl;
	AVLTree<Team> test8;
	test8.insert(t1);
	test8.printTree(test8.root);
	std::cout << "---------------------------------" << std::endl;
	AVLTree<Player>test9;



}