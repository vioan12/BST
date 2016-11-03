#include "prototypes.h"
void Display(Node* root, int nivel)
{
	int i;
	if (root != 0)
	{
		Display(root->right, nivel + 1);
		for (i = 0; i <= nivel; i++)
			printf("      ");
		printf("%d\n", root->data);
		Display(root->left, nivel + 1);
	}
}

//programul va primi ca parametru numărul pe care trebuie să îl adauge
Node *Add_Node(Node *root,int data)
{//verificam mai intai dacă există o rădăcină (dacă arborele a fost creat)
//Alocam memorie pentru noul nod si stabilim valorile pentru data,left_child,right_child.

    if(root==NULL)
    {   root=(Node *)malloc(sizeof(Node));
        root->data=data;
        root->left=root->right=NULL;
    }
    else if(data <= root->data)
    {
        root->left=Add_Node(root->left,data);//se aseaza in stanga parintelui daca este mai mic
    }
    else {
        root->right=Add_Node(root->right,data);//se aseaza in dreapta parintelui daca este mai mare
    }
    return root;
}
void preorder (Node *root)//RSD
{
    //daca nu s-a ajuns la ultimul nod
    if(root!=NULL)
    {
        //se viziteaza radacina
    printf("\n%d",root->data);
    //se viziteaza copilul din stanga apoi cel din dreapta
    preorder(root->left);
    preorder(root->right);
}
}
void inorder(Node *root) //SRD
{
    //daca nu s-a ajuns la ultimul nod
    if(root!=NULL)
    {
        inorder(root->left);//se viziteaza copilul din stanga
        printf("\n%d",root->data);//se viziteaza radacina
        inorder(root->right);//se viziteaza copilul din dreapta
    }
}
void postorder(Node *root)
{
    if (root!=NULL)//daca nu s-a ajuns la ultimul nod
    {
        postorder(root->left);//se viziteaza copilul din dreapta
        postorder(root->right);//se viziteaza copilul din stanga
        printf("\n%d",root->data);//se viziteaza radacina
    }
}

Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

void Delete( Node *root, int data) {
     int sw;
	while((root->data != data) && (root != NULL)){
        if(data < root->data)
            root=root->left;
        else
            if (data > root->data)
                root=root->right;
	}
	printf("\n%d asta e data",root->data);
    // Cazul 1:
    if(root->left == NULL && root->right == NULL){
        free(root);
        root = NULL;
    }
    //Cazul 2:
	else
        if(root->left == NULL){
            Node *temp = root;
            root = root->right;
            free(temp);
        }else
            if(root->right == NULL){
                Node *temp = root;
                root = root->left;
                free(temp);
            }else{
            // Cazul 3:
                Node *temp = FindMin(root->right);//mergem in dreapta si cautam  nr minim
                root=temp;
                sw=1;
                while(sw==1){
                    sw=0;
                    if(root->left == NULL && root->right == NULL){
                        free(root);
                        root = NULL;
                    }
                    else
                        if(root->left == NULL){
                            Node *temp = root;
                            root = root->right;
                            free(temp);
                        }else
                            if(root->right == NULL){
                                Node *temp = root;
                                root = root->left;
                                free(temp);
                            }else{
                                sw=1;
                                Node *temp = FindMin(root->right);
                                root=temp;
                            }
                }
            }
}

NodeAVL* deleteAVLNode_2( NodeAVL *node, int value)
{
	if (node == NULL)
	{
		printf("Can't delete key %d, it is not in AVL tree!\n", value);
		return node;
	}

	if ( value < node->key )
		node->left = deleteAVLNode(node->left, value);

	else if( value > node->key )
		node->right = deleteAVLNode(node->right, value);

	else
	{
        // node with only one child or no child
		if( (node->left == NULL) || (node->right == NULL) )
		{
			NodeAVL *temp;

			if( node->left != NULL )
				temp = node->left;
			else
				temp = node->right;
 
            // No child case
			if(temp == NULL)
				node = NULL;

			else // One child case
			{
				*node = *temp; 
				free(temp);
			}
        }
		else
		{
            // node with two children: Get the inorder successor
            // (smallest in the right subtree)
			NodeAVL * temp = node->right;

			while (temp->left != NULL)
				temp = temp->left;
 
            // Copy the inorder successor's data to this node
			node->key = temp->key;
 
            // Delete the inorder successor
			node->right = deleteAVLNode(node->right, temp->key);
		}
	}
 
    // If the tree had only one node then return
    if (node != NULL)
		node = balance(node);

	return node;   
}
