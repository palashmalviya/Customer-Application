//*******************************************************************************************************************************************************************
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<process.h>
//*******************************************************************************************************************************************************************
int search;
static int cid;


//
//
//
// All Structure Start------->>>>>
//
//
//


//*******************************************************************************************************************************************************************
//
// customer structure
//
typedef struct customer 
{
        int id;
        char name[50];
        char address[50];
} customers;

customers cust;
//*******************************************************************************************************************************************************************

//*******************************************************************************************************************************************************************
//
// Product structure
//
typedef struct Product 
{
        int id;
        char name[50];
        char category[50];
        int rate;
} products;

products prd;


typedef struct prdf 
{
        int id;
        char name[50];
        char category[50];
        int rate;
} fprd;

typedef struct NODE
{
	fprd data;
	struct NODE *next;

}NODE;
NODE *head=NULL;



//*******************************************************************************************************************************************************************

//*******************************************************************************************************************************************************************
//
// order structure with date structure
//
typedef struct Order 
{
        int id;
        int customer_id;
        int product_id;
        int quantity;
        int status;

         //
         // Date structure inside order
         //
            struct Date
            {
                  int day;
                  int month;
                  int year;
        
            } d;
        
} orders;
 
 orders ord;
//*******************************************************************************************************************************************************************


//
//
//
// All Structure End <<<<<-------
//
//
//
//*******************************************************************************************************************************************************************



//*******************************************************************************************************************************************************************
//
//Customer Menu Function
//
 int customer_menu()
 {  int cmm;

    do
    {      
        printf("\n\n\t\tCustomer Menu\n");
        printf("\t\t---------\n");
        printf("\n\t\t0. Exit\n");
        printf("\t\t1. List Product Category \n");
        printf("\t\t2. Products(Sort By Name)\n");
        printf("\t\t3. Products(Sort By Price)\n");
        printf("\t\t4. Order  Item\n");
        printf("\t\t5. List Pending Order\n");
        printf("\t\t6. List Delivered Order\n");
        printf("\t\tEnter Choice :  ");

        scanf("%d",&cmm);
        switch(cmm)
        {
            case 1:     
                listall_product_category();
                break;
            case 2:
                product_sort_name();
                break;
            case 3:
                product_sort_price();
                break;
            case 4:
                Order();
                break;
            case 5:
                cust_ord_status();
                break;
            case 6:
                cust_deliverorder();
                break;
            case 0:
                break;
            default:
                printf("Wrong Selection....");
                break;
        }
        
    }while(cmm!=0);
      
    
return 0;

 } 
//*******************************************************************************************************************************************************************


//*******************************************************************************************************************************************************************
//
//Admin Menu Function
//
 int menu_admin(void)
 {  int cmm;

     do
    {      
        printf("\n\n\t\tAdmin Menu\n");
        printf("\t\t---------\n");
        printf("\n\t\t0. Exit\n");
        printf("\t\t1. List Product Category\n");
        printf("\t\t2. Add Product Category\n");
        printf("\t\t3. List All Products\n");
         printf("\t\t4. Product by Name \n");
        printf("\t\t5. Edit Product\n");
        printf("\t\t6. Delete Product\n");
        printf("\t\t7. List Pending Order\n");
        printf("\t\t8. List Delivered Orders\n");
        printf("\t\t9. Dispatch Order\n");
        printf("\t\t10. Add Product\n");
        printf("\t\tEnter Choice :  ");

        scanf("%d",&cmm);
        switch(cmm)
        {
            case 1:
     
            listall_product_category();
            break;
            case 2:      
            product_category();
            break;
            case 3:
            listall_product();
            break;
            case 4:
            findprdbyname();
            break;
            case 5:
            editProduct();
            break;
            case 6:
            delProduct();
            break;
            case 7:
            ord_status();
            break;
            case 8:
            deliverorder();
            break;
            case 9:
            dispatched();
            break;
            case 10:
            products_details();
            break;
            case 0:
                break;
            default:
            printf("Wrong Selection....");
            break;
        }
        
    }while(cmm!=0);
    
return 0;

 } 
//*******************************************************************************************************************************************************************


//*******************************************************************************************************************************************************************
//
//Main Menu
//
int main_menu()
{
  int choice;
do
     {      
        printf("\n\n\t\tMain Menu\n");
        printf("\t\t---------\n");
        printf("\n\t\t0. Exit\n");
        printf("\t\t1. Register Customer\n");
        printf("\t\t2. Customer\n");
        printf("\t\t3. Admin\n");
        printf("\t\tEnter Choice :  ");

        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            customer_registration();
            break;

            case 2:
            customer_search();
            break;

            case 3:
            menu_admin();
            break;

            case 0:
            printf("Exiting....");
            break;

            default:
            printf("Wrong Selection....");
            break;
        }
        
    }while(choice!=0);
    
return 0;
}

//**********************************************************************************************************************************************
















//*******************************************************************************************************************************************************************
//
//
//
//Main Function Start------>>>>>
//
//
//
int main()
{

    
   
    printf("\n--------------------------------------------------------------\n");
    printf("Student Name    :   Palash Malviya\n");
    printf("Roll Number     :   36037\n");
    printf("Center Name     :   Sunbeam Pune\n");
    printf("Course Name     :   PG-DAC\n");
    printf("Group Name      :   \n");
    printf("Mission Statement:  I will NEVER QUIT\n");
    printf("--------------------------------------------------------------\n");

    

    main_menu();
   

    return 0;
}

//
//
//
//Main Function End<<<<<---------
//
//
//



//*******************************************************************************************************************************************************************
//
//
//
//All Functions Defination
//
//
//

//*******************************************************************************************************************************************************************
//
//Function to Customer Add or Register
//
 
int customer_registration()
{   
    FILE *fp;
	fp = fopen("customer.txt", "w+");

	if (fp != NULL) {
		printf("\nEnter Custmer ID :   ");
        scanf("%d",&cust.id);
        _flushall();

        printf("\nEnter Customer Name :   ");
        scanf("%s",cust.name);
        _flushall();

        printf("\nEnter Customer Address :   ");
        scanf("%s",cust.address);

		if(fwrite(&cust, sizeof(cust), 1, fp)==1)
        {
                    printf("\n\n\tCustomer Added Sucessfully..........\n");
                    printf("\n------------------------------------------------------------\n");
        
        }
        else
        {
            printf("\n\n\tCustomer NOT Added!!!\n");
        }
        
		fclose(fp);
	
	} 
    else
		printf("Error!!!!!.....");

return 0;
}

//*******************************************************************************************************************************************************************

//
//Customer Search By Customer ID
//
int customer_search(void)
   {	   int check;
        check=validation();
     if (check==1)
    {
        printf("\n\t\t-----------------------------------");
        printf("\n\t\tName 	   :  %s \n",cust.name);
        printf("\t\t-----------------------------------");
	    customer_menu();
    }
    else
    {
        printf("Invalid Customer!!");
        main_menu();   
    }
       return 0;
    }

//*******************************************************************************************************************************************************************
//
//Customer Validation
//
int validation()
{
    FILE *fp;
	fp = fopen("customer.txt", "r");
	if (fp != NULL)
    {	
		printf("\n\tEnter Customer ID : ");
		scanf("%d", &cid);
		while (fread(&cust, sizeof(cust), 1, fp) != '\0')
         {
			if (cust.id == cid)
             {
				return 1;
             }
         }
         fclose(fp);
    }
    return 0;
}

//*******************************************************************************************************************************************************************
//
//Add Products Details 
//
int products_details()
{   
    FILE *fp;
	fp = fopen("product.dat", "ab");

	if (fp != NULL) 
    {
        printf("\n\n\tEnter Product ID : ");
        scanf("%d",&prd.id);
        _flushall();

        printf("\n\tEnter Product Name : ");
        scanf("%s",prd.name);
        _flushall();  

        printf("\n\tEnter product Category : ");
        scanf("%s",prd.category);
        _flushall();

        printf("\n\n\tEnter product Rate : ");
        scanf("%d",&prd.rate);
        _flushall();
		
		if(fwrite(&prd, sizeof(prd), 1, fp)==1)
        {
            
            printf("\n\n\tProduct Added Sucessfully..........\n\n");
            printf("\n------------------------------------------------------------\n");
        }
		fclose(fp);
	
	} 
    else
		printf("Error!!!!!.....");
   return 0;
}
//*******************************************************************************************************************************************************************
//
//Add Products Category 
//
int product_category(void)
 {  
    char category[20];
    FILE *fp;
    fp=fopen("categories.txt","a");

    if (fp != NULL) 
    {
        printf("\n\tEnter Category :    ");
        scanf("%s",category);
        if(fprintf(fp, "%s , ", category)==1)
        {
            
            printf("\n\tCategory Added Sucessfully..........\n");
            printf("\n------------------------------------------------------------\n");
        }
        fclose(fp);
    } 
    else
		printf("Error!!!!!.....");

return 0;
 }
//*******************************************************************************************************************************************************************
//
//Display All Products Category 
//
int listall_product_category()
 {  
    char category[20];
    int index=1; 
    FILE *fp;
    fp = fopen("categories.txt","r");
       
    if (fp != NULL) 
    {
        fscanf(fp,"%s", category);
        char* token = strtok(category,",");
        printf("\n\tCategories : \n");
        while (token != NULL) 
        {
            printf("\n\t\t %d.\t%s",index++, token);
	        token = strtok(NULL, ",");
        }
        fclose(fp); 
    }
   return 0;
 }
//*******************************************************************************************************************************************************************
//
//Display All Products 
//
int listall_product(void)
{ 
    FILE *fp;
	fp = fopen("product.dat", "rb");
	if (fp != NULL)
    {	printf("\tAll Products:");
    printf("\n\t-----------------------------------");
		while (fread(&prd, sizeof(prd), 1, fp) != '\0')
		    {	
             
             
             printf("\n\t\tProduct Name 	   :  %s ",prd.name);
             printf("\n\t\tProduct ID	       :  %d ",prd.id);
             printf("\n\t\tProduct Rate 	   :  %d ",prd.rate);
             printf("\n\t\tProduct Category    :  %s \n",prd.category);
             printf("\n\t\t-----------------------------------");
	
	        }
            fclose(fp);
    }
		return 0;
}
//*******************************************************************************************************************************************************************
//
//Display All Products (Sorted by Price)
//

int cmpfuncpr(const void * p1, const void * p2) {
	int p = ((fprd *)p1)->rate;
	int pp = ((fprd *)p2)->rate;
	return (p - pp);
}


int product_sort_price()
{   
    int prdcount=0;
    FILE *fptr;
    fptr = fopen("product.dat", "rb+");
	if (fptr != NULL)
    {	
		while (fread(&prd, sizeof(prd), 1, fptr) != '\0')
		    {
                ++prdcount;
                
	        }
            fclose(fptr);
    }

   products prdarrs[ prdcount ];
   	FILE *fp;
	fp = fopen("product.dat", "rb+");
	if (fp != NULL) 
    {      
            int i = 0;
        	while (!feof(fp))
		    {	             
                products prd;
                fread(&prd, sizeof(prd), 1, fp); 
                if( !feof(fp))
                {    
                    prdarrs[ i ++ ] = prd;

                }
	
	        }
            fclose(fp);
      
    }
    else
		printf("\nError!!!");
		
        
		
		qsort(prdarrs, prdcount, sizeof(fprd), cmpfuncpr);

		for (int i = 0; i < prdcount; i++) {
			printf("\n\tProduct ID : %d", prdarrs[i].id);
			printf("\n\tProduct Name : %s", prdarrs[i].name);
			printf("\n\tCategory : %s", prdarrs[i].category);
			printf("\n\tRate : %d", prdarrs[i].rate);
            printf("\n------------------------------------------------------------\n");
		}

        
        return 0;
}

//*******************************************************************************************************************************************************************
//
//Display All Products (Sorted by Name)
//


int cmpfuncna(const void * p1, const void * p2) 
{
	int p = ((fprd *)p1)->name;
	int pp = ((fprd *)p2)->name;
	return (p - pp);
}


int product_sort_name()
{
         int prdcount=0;
    FILE *fptr;
    fptr = fopen("product.dat", "rb+");
	if (fptr != NULL)
    {	
		while (fread(&prd, sizeof(prd), 1, fptr) != '\0')
		    {
                ++prdcount;
                
	        }
            fclose(fptr);
    }

   products prdarrs[ prdcount ];
   	FILE *fp;
	fp = fopen("product.dat", "rb+");
	if (fp != NULL) 
    {      
            int i = 0;
        	while (!feof(fp))
		    {	             
                products prd;
                fread(&prd, sizeof(prd), 1, fp); 
                if( !feof(fp))
                {    
                    prdarrs[ i ++ ] = prd;

                }
	
	        }
            fclose(fp);
      
    }
    else
		printf("\nError!!!");
		
        
		
		qsort(prdarrs, prdcount, sizeof(fprd), cmpfuncpr);

		for (int i = 0; i < prdcount; i++) {
			printf("\n\tProduct ID : %d", prdarrs[i].id);
			printf("\n\tProduct Name : %s", prdarrs[i].name);
			printf("\n\tCategory : %s", prdarrs[i].category);
			printf("\n\tRate : %d", prdarrs[i].rate);
            printf("\n------------------------------------------------------------\n");
		}

        
        return 0;
}

//*******************************************************************************************************************************************************************
//
//Edit Product
//
int editProduct()
{
	FILE *fp;
	fp = fopen("product.dat", "rb+");
	if (fp != NULL) {
		int pid, flag = 0;
		printf("Enter Product ID : ");
		scanf("%d", &pid);
		while (fread(&prd, sizeof(prd), 1, fp) != '\0') {
			if (prd.id == pid)
             {

            
				printf("\n\n\t Enter Updated Product\n");
				printf("\n\n\tEnter Product ID : ");
                scanf("%d",&prd.id);
                _flushall();

                printf("\n\tEnter Product Name : ");
                scanf("%s",prd.name);
                _flushall();  

                printf("\n\tEnter product Category : ");
                scanf("%s",prd.category);
                _flushall();

                printf("\n\n\tEnter product Rate : ");
                scanf("%d",&prd.rate);
                _flushall();

				fseek(fp, -sizeof(prd), SEEK_CUR);
				if(fwrite(&prd, sizeof(prd), 1, fp)==1)
                {
                    printf("\n\tProduct Updated Successfully");
                    printf("\n------------------------------------------------------------");
                    break;
                }
                else
                {
                    printf("\n\tWrong Product ID or Product Not Inserted\n");
                    printf("------------------------------------------------------------\n");
                    break;

                }
            }
		}
		fclose(fp);
	}
    return 0;
}
//*******************************************************************************************************************************************************************
//
//Delete Product
//

int delProduct()
{		int id, flag = 0;
    FILE *fp;
	fp = fopen("product.dat", "rb+");
	if (fp != NULL) 
    {

		printf("Enter Product ID : ");
		scanf("%d", &id);
		FILE *ft = fopen("TempProductFile.dat", "wb");

		while (fread(&prd, sizeof(prd), 1, fp)) 
        {
			if (prd.id != id)
            {
				fwrite(&prd, sizeof(prd), 1, ft);
			}
			if (prd.id == id)
				flag = 1;
		}
		fclose(fp);
		fclose(ft);
		remove("product.dat");
		rename("TempProductFile.dat", "product.dat");
		if (flag == 1)
			{   
                printf("\n\tProduct Removed.");
                printf("\n------------------------------------------------------------\n");
            }
        else
			{
                printf("\n\tUnable to Find the Product");
                printf("\n------------------------------------------------------------\n");
            }
	}else
		printf("Error!!....");
        return 0;
}
//*******************************************************************************************************************************************************************
//
//Find Product by name
//
int findprdbyname()
{
	FILE *fp;
	fp = fopen("product.dat", "rb");
	if (fp != NULL) 
    {
		char name[20];
		int flag = 0;
		printf("Enter Product Name  : ");
		scanf("%s", name);
		while (fread(&prd, sizeof(prd), 1, fp) != '\0') {
			if (strncmp(prd.name, name, 1) == 0)
			 {
				    printf("\n\tProduct(s) :");
					printf("\n\tID : %d", prd.id);
	                printf("\n\tName : %s", prd.name);
	                printf("\n\tCategory : %s", prd.category);
	                printf("\n\tRate : %d", prd.rate);
                    printf("\n------------------------------------------------------------\n");
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			printf("\n\tNo Such Product.");
		fclose(fp);
	}else
		printf("\nError!!");
        return 0;
}

//*******************************************************************************************************************************************************************
//
//Order Product
//

 int Order()
 {  int count=1;
	
    	FILE *fptr;
	        fptr = fopen("orders.dat", "rb");
	        if (fptr != NULL) 
        {
		    while(fread(&ord, sizeof(ord), 1, fptr)!='\0')
            {
                count++;
		    }
		fclose(fptr);
        }
    FILE *pfp;
    FILE *fp;
    pfp=fopen("product.dat","rb+");
	fp = fopen("orders.dat", "wb+");
	if (fp != NULL && pfp != NULL)
    {

    printf("\n\tEnter Order Details");
    printf("\n\t-------------------\n");

    ord.id=count;
    ord.customer_id=cid;
 
    ord.status=0;
    printf("\n\tTemporary Order ID : %d",ord.id);
	printf("\n\tCustomer ID : %d",ord.customer_id);
	_flushall();

    printf("\n\tProduct ID : ");
	scanf("%d", &ord.product_id);
    _flushall();
    
    if(ord.product_id==prd.id)
    {
    printf("\n\tProduct Name :%s",prd.name);
    printf("\n\tProduct Price :%d",prd.rate);
	printf("\n\tQuantity : ");
    scanf("%d", &ord.quantity);
    _flushall();
    printf("\n\tEnter Date (DD/MM/YYYY)  :");
    scanf("%d %d %d",&ord.d.day,&ord.d.month,&ord.d.year);
    _flushall();
    
    
		if(fwrite(&ord, sizeof(ord), 1, fp)==1)
        {    
            printf("\n\tPermanent Order ID is :  %d ",ord.id);
	        printf("\n---------------------------------------------------\n");
        }
    }else
    {
        printf("\n\tProduct Not Found..Sorry!");
    }
    
        fclose(pfp);             
		fclose(fp);

	} else
		printf("\n\tError!!!");
        return 0;
 }
//*******************************************************************************************************************************************************************
//
//Order Product Status of pending
//
int ord_status()
{
	FILE *fp;
	fp = fopen("orders.dat", "rb");
	int flag =0;
	if (fp != NULL) 
    {
		while(fread(&ord, sizeof(ord), 1, fp)!='\0')
        {
			if(ord.status==0)
            {
			    printf("\n\tOrder Id : %d",ord.id);
	            printf("\n\tCustomer ID : %d",ord.customer_id);
	            printf("\n\tProduct ID : %d",ord.product_id);
	            printf("\n\tQuantity : %d",ord.quantity);
                printf("\n\tDate (DD/MM/YYYY) : %d / %d / %d",ord.d.day,ord.d.month,ord.d.year);
                printf("\n------------------------------------------------------------\n");
				flag =1;
			}
		}
		if(flag==0)
        {
			printf("No Pending Order\n");
            printf("\n------------------------------------------------------------\n");
		}
		fclose(fp);
	} else
		printf("\nError!!!");
        return 0;
}

//*******************************************************************************************************************************************************************
//
//Order Product Status of pending(Customer)
//
int cust_ord_status()
{
	FILE *fp;
	fp = fopen("orders.dat", "rb");
	
	if (fp != NULL) 
    {  int flag =0;
		while(fread(&ord, sizeof(ord), 1, fp)!='\0')
        {
           
			if(ord.status==0 && ord.customer_id == cid)
            {
			    printf("\n\tOrder Id : %d",ord.id);
	            printf("\n\tCustomer ID : %d",ord.customer_id);
	            printf("\n\tProduct ID : %d",ord.product_id);
	            printf("\n\tRate : %d",ord.quantity);
	            printf("\n\tDate (DD/MM/YYYY) : %d / %d / %d",ord.d.day,ord.d.month,ord.d.year);
                printf("\n------------------------------------------------------------\n");
				flag =1;
			}
		}
		if(flag==0)
        {
			printf("No Pending Order\n");
            printf("\n------------------------------------------------------------\n");
		}
		fclose(fp);
	} else
		printf("\n\nError!!!");
        return 0;
}


 //*******************************************************************************************************************************************************************
//
//Order Product Status of delivered 
//
int deliverorder()
{
	FILE *fp;
	fp = fopen("orders.dat", "rb");
	int flag = 0;
	if (fp != NULL) 
    {
		while (fread(&ord, sizeof(ord), 1, fp) != '\0') 
        {
			if (ord.status == 1) 
            {
			    printf("\n\tOrder Id : %d",ord.id);
	            printf("\n\tCustomer ID : %d",ord.customer_id);
	            printf("\n\tProduct ID : %d",ord.product_id);
	            printf("\n\tRate : %d",ord.quantity);
	            printf("\n\tDate (DD/MM/YYYY) : %d / %d / %d",ord.d.day,ord.d.month,ord.d.year);
				flag = 1;
			}
		}
		if (flag == 0) 
        {
			printf("\n\tNo Delivered Orders.");
            printf("\n------------------------------------------------------------\n");
		}
		fclose(fp);
	} else
		printf("\nError!!!");
        return 0;
}

 //*******************************************************************************************************************************************************************
//
//Order Product Status of delivered (Customer)
//
int cust_deliverorder()
{
	FILE *fp;
	fp = fopen("orders.dat", "rb");
	int flag = 0;
	if (fp != NULL) 
    {
		while (fread(&ord, sizeof(ord), 1, fp) != '\0') 
        {
			if (ord.status == 1 && ord.customer_id == cid) 
            {
			    printf("\n\tOrder Id : %d",ord.id);
	            printf("\n\tCustomer ID : %d",ord.customer_id);
	            printf("\n\tProduct ID : %d",ord.product_id);
	            printf("\n\tRate : %d",ord.quantity);
	            printf("\n\tDate (DD/MM/YYYY) : %d / %d / %d",ord.d.day,ord.d.month,ord.d.year);
                printf("\n------------------------------------------------------------\n");
				flag = 1;
			}
		}
		if (flag == 0) 
        {
			printf("\n\tNo Delivered Orders.");
            printf("\n------------------------------------------------------------\n");
		}
		fclose(fp);
	} else
		printf("\nError!!!");
        return 0;
}

 //*******************************************************************************************************************************************************************
//
//Order dispatched
//


int dispatched()
{   
    int ooid,stat;
    FILE *fp;
	fp = fopen("orders.dat", "rb+");
	if (fp != NULL)
    {	
		printf("\n\tEnter Order ID : ");
		scanf("%d", &ooid);
		while (fread(&ord, sizeof(ord), 1, fp) != '\0')
         {
             
			if (ord.id == ooid)
             {
				printf("\n\tOrder Id : %d",ord.id);
	            printf("\n\tCustomer ID : %d",ord.customer_id);
	            printf("\n\tProduct ID : %d",ord.product_id);
	            printf("\n\tRate : %d",ord.quantity);
	            printf("\n\tDate (DD/MM/YYYY) : %d / %d / %d",ord.d.day,ord.d.month,ord.d.year);
                printf("\n\n\t\tOrder Status : %d",ord.status);
                printf("\n\t\tOrder Found.\n\t Enter Updated Delivery Report 1 for delivered, 0 for Pending, 2 for Dispatched : ");
                scanf("%d",&stat);
                ord.status=stat;
             	fseek(fp, -sizeof(ord), SEEK_CUR);
				if(fwrite(&ord, sizeof(ord), 1, fp)==1)
                {
                    printf("\n\tOrder Status Updated Successfully");
                    printf("\n------------------------------------------------------------\n");
                    fclose(fp); 
                }
                else
                {
                    printf("\n\tOrder Status Unchanged\n");
                    printf("\n------------------------------------------------------------\n");
                }
        
             }

         }
    }	
    return 0;     		
}

    
    
        