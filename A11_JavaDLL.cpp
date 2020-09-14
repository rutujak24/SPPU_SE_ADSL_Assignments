
 
 
package specificList;
 
import common.commonList;
import java.util.Scanner;
 
class Node
{
    public int data;
    public Node next;
    public Node previous;
 
    public Node()
    {
        previous = null;
        next = null;
        data = 0;
    }
 
    public Node(int d, Node n, Node p)
    {
        data = d;
        next = n;
        previous = p;
    }
}
 
public class DLL implements commonList
{
 
    Node head;
    int size;
 
    DLL()
    {
        head = null;
        size = 0;
    }
 
    public boolean isEmpty()
    {
        return head == null;
    }
 
    public void add(int val)
    {
        Node newNode = new Node(val, null, null);
        size++;
        if (isEmpty()) 
        {
            head = newNode;
        }
        else
        {
            Node temp=head;
            while(temp.next!=null)
                temp=temp.next;
            temp.next=newNode;
            newNode.previous=temp;
        }
    }
    public void remove(int val1)
    {
        if(isEmpty())
        {
            System.out.println("The list is empty.");
        }
        else            
        {
            if(head.next==null && head.data==val1)
            {
                head=null;
                size--;
            }
            else if(head.next!=null && head.data==val1)
            {
                head = head.next;
                head.previous=null;
                size--;
            }
            else
            {
                Node temp = head;
                while(temp.next!=null )
                {
                    if(temp.data == val1)
                    {
                        Node temp2 = temp.previous;
                        temp2.next = temp.next;
                        temp2.next.previous=null;
                        temp.next=null;
                        temp.previous=null;
                        size--;
                        return;
                    }
                    temp = temp.next;
                }
                if(temp.data == val1)
                {
                    Node temp2 = temp.previous;
                    temp2.next=null;
                    temp.next=null;
                    temp.previous=null;
                    size--;
                }
                else
                {
                    System.out.println("Element not found!");
                }
            }
        }
    }
    public int size()
    {
        return size;
    }
    public void display()
    {
        System.out.print("SLL:-   ");
        if (size == 0) 
        {
        System.out.print("empty\n");
        return;
        }    
        if (head.next == null) 
        {
           System.out.println(head.data);
            return;
        }
 
        Node ptr = head;
        while (ptr.next != null)
        {
           System.out.print(ptr.data+ " <-> ");
            ptr = ptr.next;
        }
        System.out.print(ptr.data+ " <-> \n");
    }
    public void search(int se)
    {
        if (size == 0) 
        {
        System.out.print("empty\n");
        return;
        }   
        Node temp= head;
        while(temp!=null)
        {
            if(temp.data==se)
            {
                System.out.println("Element Found!");
                return;
            }
            temp=temp.next;
        }
        System.out.println("Element not found!");
    }
    public void modify(int mo)
    {
        if (size == 0) 
        {
        System.out.print("empty\n");
        return;
        }   
        Node temp= head;
        while(temp!=null)
        {
            if(temp.data==mo)
            {
                Scanner y=new Scanner(System.in);
                System.out.print("Enter new value: ");
                int z=y.nextInt();
                temp.data=z;
                return;
            }
            temp=temp.next;
        }
        System.out.println("Element not found!");
    }
    public static void main(String[] args)
    {   
        DLL S1=new DLL();
        Scanner x=new Scanner(System.in);
        int a,b;
        System.out.print("Enter the number of terms: ");
        a = x.nextInt();
        while (a!=0)
        {
            System.out.print("Enter the number: ");
            b=x.nextInt();
            S1.add(b);
            a--;
        }
        S1.display();
        int c;
        while(true)
        {
            System.out.println("1.Add  2.Remove  3.Display  4.Size  5.Search  6.Modify  0.Exit");
            int choice;
            choice = x.nextInt();
            switch(choice)
            {
            case 1:
                System.out.print("Enter the number: ");
                c=x.nextInt();
                S1.add(c);
                break;
            case 2:
                System.out.print("Enter the number: ");
                c=x.nextInt();
                S1.remove(c);
                break;
            case 3:
                S1.display();
                break;
            case 4:
                System.out.println("Size: " + S1.size());
                break;
            case 5:
                System.out.print("Enter the number: ");
                c=x.nextInt();
                S1.search(c);
                break;
            case 6:
                System.out.print("Enter the number: ");
                c=x.nextInt();
                S1.modify(c);
                break;
            case 0:            
                return;
            default:
                System.out.print("Wrong choice!");
                break;
            }
        }
    }
    
}



//ANOTHER PACKAGE COMMON IN A DIFFERENT JAVA CODE

package common;
 
public interface commonList{
    void add(int x);
    void remove(int y);
    void display();
    boolean isEmpty();
    int size();
    void search(int se);
    void modify(int mo);
}


