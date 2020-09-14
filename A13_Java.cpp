import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;


public class Assignment13 {
	public static void main(String[] args) throws Exception
	{
		Scanner sc=new Scanner(System.in);
		int choice;

		PriorityQueue<Integer> q1=new PriorityQueue<>();
		Stack<Integer> s1=new Stack<>();
		LinkedList<Integer> l1=new LinkedList<>();
		ArrayList<Integer> arrayList=new ArrayList<>();
		HashMap<String, Integer> hs=new HashMap<>();
		do
		{
			System.out.println("\n1. Queue 2.Stack  3.Linked List  4.ArraList  5.Map  0.Exit\nENter your choice:");
			choice=sc.nextInt();
			switch(choice)
			{
			case 1:

				System.out.println("1. Enqueue  2.Dequeue  0.Exit");
				choice=sc.nextInt();
				switch(choice)
				{
				case 1:
					System.out.println("\nEnter Number: ");
					q1.add(new Integer(sc.nextInt()));
					System.out.println("Added :"+q1.peek());
					System.out.println("MODIFIED QUEUE : ");
					for(int s : q1) 
					{ 
  						System.out.print(s+"   "); 
					}
					break;
				case 2:
					System.out.println("\nRemoved element:=>"+q1.remove());
					break;

				case 0:
					break;

				}
				break;
			case 2:
				System.out.println("\n1.Push  2.Pop  3.Top  4.Exit\n");
				choice=sc.nextInt();
				switch(choice)
				{
				case 1:
					System.out.println("\nENter Number: ");
					s1.push(new Integer(sc.nextInt()));
					break;
				case 2:
					System.out.println("\nPopped elemet:=> "+s1.pop());
					break;
				case 3:
					System.out.println("\nStack top: "+s1.peek());
					break;
				case 4:
					break;
				}
				break;
			case 3:

				System.out.println("\n====Linked LIST =====\n 1.Add  2.Remove  3.First  4.Last");
				choice=sc.nextInt();
				switch(choice)
				{
				case 1:
					System.out.println("\nEnter Number: ");
					l1.add(new Integer(sc.nextInt()));
					break;
				case 2:
					System.out.println("\nEnter position of element to remove: ");

					System.out.println("\nRemoved element:"+l1.remove(sc.nextInt()));
					break;
				case 3:
					System.out.println("\nFirst Element: "+l1.getFirst());
					break;
				case 4:
					System.out.println("\nLast Element: "+l1.getLast());
					break;
				case 5: break;
				}
				break;
			case 4:
				System.out.println("\n====ARRAY LIST ========");
				arrayList.add(new Integer(10));
				arrayList.add(new Integer(20));
				System.out.println("10 added\n20added");
				System.out.println("Removed element  at index 0 from arrayList: "+arrayList.remove(0));
				System.out.println("\nSize: "+arrayList.size());
				break;

			case 5:
				System.out.println("\n===== Hash Map=====");

				{
					System.out.println("\nEnter Key");
					String key=sc.nextLine();
					key=sc.nextLine();
					System.out.println("\nEnter Value: ");
					int value=sc.nextInt();
					hs.put(key, value);
					System.out.println("\nRecord Insserted");
					hs.put("roll",21168);
					hs.put("Div", 1);

					System.out.println("\nRemoved element (roll):"+hs.remove("roll"));

					System.out.println("\nSize: "+hs.size());
					System.out.println("\nHashcode Value for this map: "+hs.hashCode());

				}
				break;
			default:
				System.out.println("\nWrong Choice");


			}
		}while(choice!=0);
	}
}



