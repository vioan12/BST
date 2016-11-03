#include"prototypes.h"
FILE *file;


int main()

{
    int i,n,x;
    file=fopen("in.txt","r");
    rt=NULL;
    do{
    printf("\n1.Adaugare noduri fisier");
    printf("\n2.Sterge un nod");
    printf("\n3.Preorder");
    printf("\n4.Inorder");
    printf("\n5.Postorder");
	printf("\n6.Arborescenta");
    printf("\n\nOptiunea dumneavoastra: ");
    scanf("%d",&i);
   switch(i)
   {
   case 1:
    fscanf(file,"%d",&n);
    do{
        rt=Add_Node(rt,n);
        fscanf(file,"%d",&n);
    }while(!feof(file));
    fclose(file);
    break;
   case 2:
    printf("\nAlegeti nodul pe care doriti sa-l stergeti");
    scanf("%d",&x);
    Delete(rt,x);
    break;
   case 3:
    preorder(rt);
    break;
   case 4:
    inorder(rt);
    break;
   case 5:
    postorder(rt);
    break;
   case 6:
	   Display(rt, 0);
	   break;
   }



}while(i);
return 0;
}
