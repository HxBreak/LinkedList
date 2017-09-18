#include <stdio.h>
#include <stdlib.h>

/*
����ĳ�����Ϊ�����ڴ��д洢�ɱ䳤���ݣ�ʹ���ݾ��й����ԣ��������顣
*/
typedef struct LinkedList//����ṹ��
{
	int score;//�˴�����������չ
	struct LinkedList* pnextele;//�̶��ֶ�,ָ����һ��Ԫ�ص�ָ��
}list;


list* DeleteElement(list* l, int id);//ɾ��һ�������е�һ��Ԫ��
list* AppendElement(list* l);//������β�����һ��Ԫ��
int OutputElement(list* l);//������������Ԫ��

int main(){
	int opt = -1;//�û�ѡ�еĲ�����
	list* linkedlist = NULL;//һ��ָ��������Ԫ�ص�ָ��
	do{
		//���ѡ��˵�
		printf("�˵�:\n");
		printf("1.���Ԫ��\n");
		printf("2.ɾ��Ԫ��\n");
		printf("3.���Ԫ���б�\n");
		printf("0.�˳�\n###########################################\n");
		scanf("%d", &opt);//���������ѡ��
		int target = 0;//Ҫɾ����Ԫ������λ�ã�����ѡ��Ϊɾ��Ԫ��ʱ��Ч
		switch (opt)
		{
			case 1:
				linkedlist = AppendElement(linkedlist);
				break;
			case 2:
				printf("������һ��Ҫɾ����Ԫ��:");
				scanf("%d", &target);
				linkedlist = DeleteElement(linkedlist, target);
				break;
			case 3:
				OutputElement(linkedlist);
				break;
		}
	} while (opt != 0);//ѡ�Ϊ�˳�ʱ������������
	return 0;
}
list* AppendElement(list* l){
	auto src = l;//����ָ����Ԫ�ص�ָ��
	printf("������һ��Ҫ¼��ķ���:");
	list* ele = (list*)malloc(sizeof(list));//����Ԫ��
	ele->pnextele = NULL;//û����һ��Ԫ��
	scanf("%d", &ele->score);//��Ԫ�ص����ݸ�ֵ
	if (l == NULL){//�������Ϊ�գ��´�����Ԫ����Ϊ�����׷���
		return ele;
	}else{
		while (l->pnextele != NULL){//����������ĩβ
			l = l->pnextele;
		}
		l->pnextele = ele;//ĩβԪ�صı���λָ��ָ������ӵ�Ԫ��
		return src;//���ر����ָ��
	}
}int OutputElement(list* l){//ѭ����ӡ����Ԫ�ص�ֵ
	list* temp = l;
	auto order = 0;
	while (temp != NULL){
		printf("address: [0x%X]\tid:[%d]\tscore:%d\n", temp, order, temp->score);
		order++;//id����һλ
		temp = temp->pnextele;//ת���¸�Ԫ��
	}
	return 0;
}
list* DeleteElement(list* l, int id){
	/*
	�����Ԫ�غ͵�һλ��Ԫ�ز������ⷽ��ժ��
	*/
	auto src = l;//���������ͷ��ָ��
	if (id == 0){
		return l->pnextele;//ֱ�ӷ���ͷ��ָ�����һ��Ԫ��
	}else if (id == 1){//ժ��ͷ��Ԫ����ָ�����һ��Ԫ�أ���Ϊ�������
		if (l->pnextele->pnextele != NULL){//���1. ��������������Ԫ��
			l->pnextele = l->pnextele->pnextele;
		}else{//���2. ����ֻ������Ԫ��
			l->pnextele = NULL;
		}
		return src;
	}
	for (int i = 0; (id - i) != 1; i++){//�õ�ǰָ��ָ��Ҫɾ����Ԫ�����ϸ�λ�� 
										//����Ҫɾ��4����ǰ��Ӧ��ͣ����3��Ԫ�ص�λ��
		l = l->pnextele;
	}
	if (l->pnextele != NULL && l->pnextele->pnextele != NULL){//�����һ��Ԫ�غ�����һ��Ԫ�ض���Ϊ��
		l->pnextele = l->pnextele->pnextele;//�ö���Ԫ��ֱ��ָ���ĺ�Ԫ��
	}else{//����û���ĺ�Ԫ��(��������Ԫ�ص�ֵ)
		l->pnextele = NULL;//ֱ�����ö���Ԫ�ص���һ��ָ��Ϊ��
	}
	return src;//���ر����ָ��
}