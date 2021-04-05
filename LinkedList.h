#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

//LinkedList Node
template <class T>
class Node{
	public:
		//데이터를 저장할 변수
		T data;
		//노드구조체 이용; 다음노드의 주소를 저장할 포인터
		Node *link;

		Node(T element){
		  data = element;
		  link = NULL;
		}
	};

//LinkedList Class
template <class T>
class LinkedList{
	protected:
		//첫번째 노드의 주소를 저장할 포인터
		Node<T> *first;
		int current_size;
	public:
		//생성자, 초기화 
		LinkedList(){
			first = 0;
			current_size = 0;
		};

		//노드 개수를 리턴
		int GetSize(){
			return current_size;
		};

		//맨 앞에 원소를 삽입, LinkedList와 Stack 둘다 같다
		void Insert(T element){
            Node<T>* newnode = new Node<T>(element);
            newnode->link = first;
            first = newnode;
            current_size++;
        };
		
		//맨 뒤의 원소를 삭제, 제일 나중에 들어온 원소 삭제  - LinkedList
		virtual bool Delete(T &element){
            if(first==0) return false;
            Node<T>* current = first;
            Node<T>* previous = NULL;

            while(1){
                if(current->link==0){
                    if(previous) previous->link = current->link;
                    else first = first->link;
                    break;
                }
                previous=current;
                current=current->link;
            }
            element=current->data;
            delete current;
            current_size--;
            return true;
        };

		//리스트 출력
		void Print(){
            int i;
            Node<T>* current = first;
            for(int i=1; i<=current_size; i++){
                cout<<"["<<i<<"|"<<current->data<<"]";
                current = current->link;
                if(current!=0) cout<<"->";
                else break;
            }
            if(current_size!=0) cout<<endl;
        };
};


//새 노드를 맨 앞에 붙이고 값을 넣음
/*void LinkedList::Insert(int element){
	//노드 생성
	Node *newnode = new Node(element);

	//새 노드가 첫번째 노드를 가리킴
	//newnode는 포인터이기 때문에 -> 를 사용해 함수, 변수를 불러옴 newnode.link와 뜻은 같다
	newnode -> link = first;
	first = newnode;
	current_size++;
}

//마지막 노드의 값을 리턴하면서 메모리에서 할당 해제
bool LinkedList::Delete(int &element){

	if (first == 0)
		return false;
	
	Node *current = first;
	Node *previous = 0;
	
	//마지막 노드까지 찾아가는 반복문
	while(1){
		if (current->link == 0){  //마지막 노드를 찾는것
			if (previous)
				previous -> link = current -> link;
			else
				first = first -> link;
			break;
		}
		previous = current;
		current = current -> link;
	}
	element = current -> data;
	delete current;
	current_size--;

	return true;
}

//리스트를 출력하는 Print 함수
void LinkedList::Print(){
	Node *i;
	int index = 1;

	if (current_size != 0){
		for( i = first; i != NULL; i=i->link){
			if (index == current_size){
				cout << "[" << index << "|";
				cout << i -> data <<"]->";
			}
			
			else {
				cout << "[" << index << "|";
				cout << i -> data << "]->";
				index++;
			}
		}
		cout << endl;
	}

}

*/
#endif
