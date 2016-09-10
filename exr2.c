/*
Binary Tree Right Side View
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4]
link:https://leetcode.com/problems/binary-tree-right-side-view/
*/
#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef int bool;
#define true 1
#define false 0
struct DetcNode
{
	struct TreeNode *node;
	int deep;
};

struct QueNode
{
	struct DetcNode detcNodes[100];
	int front;
	int rear;
};

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool initQueue(struct QueNode *que)
{
	que->front = 0;
	que->rear = 0;
	return true;
}

/* enqueue */
bool enqueue(struct QueNode *que, struct DetcNode detcNode)
{
	if (que->front >= 100)
	{
		printf("enqueue failed, queue is full\n");
		return false;
	}
	(que->detcNodes)[que->rear] = detcNode;
	(que->rear)++;
	printf("enqueue success, que->rear = %d\n", que->rear);
	return true;
}
/* get front element and dequeue */
bool dequeue(struct QueNode *que, struct DetcNode *detcNode)
{
	/* if queue is empty, return false */
	if (que->front == que->rear)
	{
		printf("dequeue failed, queue is empty\n");
		return false;
	}
	*detcNode = (que->detcNodes)[que->front];
	(que->front)++;
	printf("dequeue success, qu->front = %d\n", que->front);
	return true;	
}

/* get front element but not dequeue */
bool getFront(struct QueNode que, struct DetcNode *detcNode)
{
	/* if queue is empty, return false */
	if (que.front == que.rear)
		return false;
	*detcNode = (que.detcNodes)[que.front];
	return true;
}

bool queEmpty(struct QueNode que)
{
	if (que.front == que.rear)
		return true;
	return false;
}
void testQueue()
{
	struct DetcNode detcNodes[10];
	int i;
	for(i = 0; i < 10; i++)
	{
		(detcNodes[i]).deep = i;
	}
	
	struct QueNode que;
	initQueue(&que);
	i = 0;
	while (i < 10 && enqueue(&que, detcNodes[i]))
	{
		i++;
	}
	struct DetcNode tempNode;
	i = 0;
	while(i < 15)
	{
		if (!dequeue(&que, &tempNode))
		{
			printf("dequeue failed, que is empty!\n");
			break;
		}
		printf("deep: %d\n", tempNode.deep);
		i++;
	}

}

int* rightSideView(struct TreeNode* root, int* returnSize) 
{
	int count = 0;
	int *tempResult = (int *)malloc(sizeof(int) * 100);
	/*create a detcNode for root node*/
	struct DetcNode detcNode;
	if (root == NULL)
		return NULL;
	detcNode.node = root;
	detcNode.deep = 1;
	/* root detcNode enqueue */
	struct QueNode que;
	initQueue(&que);
	enqueue(&que, detcNode);
	struct DetcNode frontNode;
	struct DetcNode newFrontNode;
	struct DetcNode *tempNode;
	struct TreeNode *p = root;
	while(dequeue(&que, &frontNode))
	{
		printf("enqueue success, deep:%d\n", frontNode.deep);
		if ((frontNode.node)->left != NULL)
		{
			tempNode = (struct DetcNode *)malloc(sizeof(struct DetcNode));
			tempNode->deep = frontNode.deep + 1;
			tempNode->node = (frontNode.node)->left;
			enqueue(&que, *tempNode);
		}
		if ((frontNode.node)->right != NULL)
                {
                        tempNode = (struct DetcNode *)malloc(sizeof(struct DetcNode));
                        tempNode->deep = frontNode.deep + 1;
                        tempNode->node = (frontNode.node)->right;
                        enqueue(&que, *tempNode);
                }
		if (!getFront(que, &newFrontNode))
		{	
			tempResult[count] = (frontNode.node)->val;
			count++;
			break;
		}
		if (frontNode.deep < newFrontNode.deep)
		{
			tempResult[count] = (frontNode.node)->val;
			count++;
		}
	} 
	int *result = (int *)malloc(sizeof(int) * count);
	int i;
	for(i = 0; i < count; i++)
	{
		result[i] = tempResult[i];
	}
	free(tempResult);
	*(returnSize) = count;
	return result;
}

struct TreeNode *createTree()
{
	struct TreeNode *treeNodes = (struct TreeNode *)malloc(sizeof(struct TreeNode) * 4);
	int i;
	for(i = 0; i <  4; i++)
	{
		(treeNodes[i]).val = i + 1;
		(treeNodes[i]).left = NULL;
		(treeNodes[i]).right = NULL;
	}
	(treeNodes[0]).left = treeNodes + 1;
	(treeNodes[0]).right = treeNodes + 2;
	(treeNodes[1]).right = treeNodes + 3;
	
	return treeNodes;
}

int main()
{
	struct TreeNode *root = createTree();
	int returnSize;
	int *result = rightSideView(root, &returnSize);
	int i;
	for(i = 0; i < returnSize; i++)
	{
		printf("%d", result[i]);
	}
	return 0;
}
