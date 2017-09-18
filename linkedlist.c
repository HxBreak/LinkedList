#include <stdio.h>
#include <stdlib.h>

/*
链表的出现是为了在内存中存储可变长数据，使数据具有关联性，弹性数组。
*/
typedef struct LinkedList//链表结构体
{
	int score;//此处可以任意扩展
	struct LinkedList* pnextele;//固定字段,指向下一个元素的指针
}list;


list* DeleteElement(list* l, int id);//删除一个链表中的一个元素
list* AppendElement(list* l);//在链表尾部添加一个元素
int OutputElement(list* l);//输出链表的所有元素

int main(){
	int opt = -1;//用户选中的操作项
	list* linkedlist = NULL;//一个指向链表首元素的指针
	do{
		//输出选项菜单
		printf("菜单:\n");
		printf("1.添加元素\n");
		printf("2.删除元素\n");
		printf("3.输出元素列表\n");
		printf("0.退出\n###########################################\n");
		scanf("%d", &opt);//接受输入的选项
		int target = 0;//要删除的元素所在位置，仅在选项为删除元素时有效
		switch (opt)
		{
			case 1:
				linkedlist = AppendElement(linkedlist);
				break;
			case 2:
				printf("请输入一个要删除的元素:");
				scanf("%d", &target);
				linkedlist = DeleteElement(linkedlist, target);
				break;
			case 3:
				OutputElement(linkedlist);
				break;
		}
	} while (opt != 0);//选项不为退出时继续接受输入
	return 0;
}
list* AppendElement(list* l){
	auto src = l;//保存指向首元素的指针
	printf("请输入一个要录入的分数:");
	list* ele = (list*)malloc(sizeof(list));//创建元素
	ele->pnextele = NULL;//没有下一个元素
	scanf("%d", &ele->score);//给元素的数据赋值
	if (l == NULL){//如果链表为空，新创建的元素作为链表首返回
		return ele;
	}else{
		while (l->pnextele != NULL){//遍历到链表末尾
			l = l->pnextele;
		}
		l->pnextele = ele;//末尾元素的保留位指针指向新添加的元素
		return src;//返回保存的指针
	}
}int OutputElement(list* l){//循环打印各个元素的值
	list* temp = l;
	auto order = 0;
	while (temp != NULL){
		printf("address: [0x%X]\tid:[%d]\tscore:%d\n", temp, order, temp->score);
		order++;//id自增一位
		temp = temp->pnextele;//转到下个元素
	}
	return 0;
}
list* DeleteElement(list* l, int id){
	/*
	针对首元素和第一位的元素采用特殊方法摘除
	*/
	auto src = l;//保存链表的头部指针
	if (id == 0){
		return l->pnextele;//直接返回头部指向的下一个元素
	}else if (id == 1){//摘除头部元素所指向的下一个元素，分为几种情况
		if (l->pnextele->pnextele != NULL){//情况1. 链表至少有三个元素
			l->pnextele = l->pnextele->pnextele;
		}else{//情况2. 链表只有两个元素
			l->pnextele = NULL;
		}
		return src;
	}
	for (int i = 0; (id - i) != 1; i++){//让当前指针指向要删除的元素上上个位置 
										//假如要删除4，当前就应该停留在3号元素的位置
		l = l->pnextele;
	}
	if (l->pnextele != NULL && l->pnextele->pnextele != NULL){//如果下一个元素和下下一个元素都不为空
		l->pnextele = l->pnextele->pnextele;//让二号元素直接指向四号元素
	}else{//假如没有四号元素(忽略三号元素的值)
		l->pnextele = NULL;//直接设置二号元素的下一个指针为空
	}
	return src;//返回保存的指针
}