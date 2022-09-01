class table:
    def __init__(self,address,label,datatype):
        self.address=address
        self.label=label
        self.datatype=datatype

data=[[] for _ in range(5)]

while True:

    print("\nSYMBOL TABLE(MENU) :\n")
    print("1.INSERT")
    print("2.SEARCH")
    print("3.DISPLAY")
    print("0.EXIT")
    choice=int(input("\nEnter your choice :"))

    if choice==0:
        print("Terminated Successfully !!!")
        break;

    elif choice==1:
        n=int(input("Enter the No of Symbols to be inserted :"))
        for i in range(n):
            address=int(input(f"Enter the Address of Symbol {i+1} :"))
            label=input(f"Enter the Label of Symbol {i+1}         :")
            datatype=input(f"Enter the Datatype of Symbol {i+1}   :")
            h=len(label)%5
            data[h].append(table(address,label,datatype))

    elif choice==2:
        keylabel=input("\nEnter the label to be searched for : ")
        m=len(keylabel)%5
        flag=True
        for i in data[m]:
            if i.label==keylabel:
                print("\nSymbol Found !!")
                print(f"\nAddress :{i.address}")
                print(f"Datatype  :{i.datatype}")
                print(f"Label     :{i.label}\n\n")
                flag=False
                break
        if flag:
                print("\nSymbol Not Found !!!")

    elif choice==3:
        for i in data:
            for j in i:
                print(f"\nAddress :{j.address}")
                print(f"Datatype  :{j.datatype}")
                print(f"Label     :{j.label}\n\n")
        
    else:
        print("INVALID ENTRY !")
        print("TRY AGAIN  !!")

