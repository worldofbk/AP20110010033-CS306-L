class symbol:
    def __init__(self,address,label,datatype):
        self.label=label
        self.address=address
        self.datatype=datatype

    def display(self):
        print(f"Address    :{self.address}")
        print(f"Label      :{self.label}")
        print(f"Datatype   :{self.datatype}")


    def equals(self,label):
        
        if self.label==label:
            print("SYMBOL FOUND !!")
            print(f"Address  : {self.address}")
            print(f"Label    : {self.label}")
            print(f"Datatype   :{self.datatype}")
            return True

        return False



l=[]
while True:
    print("\nSYMBOL TABLE(MENU) :\n")
    print("1.INSERT")
    print("2.SEARCH")
    print("3.DISPLAY")
    print("0.EXIT")
    choice=int(input("\nEnter your choice :"))

    if choice==1:
        n=int(input("\nEnter no of symbols to be inserted :"))
        for i in range(n):
            address=int(input(f"Enter the Address for SYMBOL {i+1}  :"))
            label=input(f"Enter the label for SYMBOL {i+1}          :")
            datatype=input(f"Enter the Datatype for SYMBOL {i+1}    :")
            print("\n")
            k=symbol(address,label,datatype)
            l.append(k)

    elif choice==2:
        keylabel=input("\nEnter the label to be Searched for :")
        for symbol in l:
            if symbol.equals(keylabel):
                break;
        else:
            print("SYMBOL NOT FOUND !!")
            

    elif choice==3:
        if len(l)==0:
            print("No data to DISPLAY!!")
            continue;
        for i in range(len(l)):
            print(f"\nSYMBOL {i+1}:-\n")
            l[i].display()
    elif choice==0:
        print("\nTerminated Successfully!!!")
        break;

    else:
        print("INVALID ENTRY !")
        print("TRY AGAIN  !!")
