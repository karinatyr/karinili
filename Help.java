class Help {
	public static void main(String args[])
		throws java.io.IOException {
 		
		char choice, ignore;

		do {
			System.out.println("Справочная система: ");
			System.out.println(" 1. if");
			System.out.println(" 2. switch");
			System.out.println("Выберите подраздел: ");
			choice = (char) System.in.read();
			do{
				ignore = (char) System.in.read();
			}while (ignore != '\n');

		} while (choice < '1'| choice > '2');
		System.out.println("\n");

		switch (choice){
			case '1':
				System.out.println("Оператор if:\n");
				System.out.println("if(условие) операторы;");
				System.out.println("else операторы;");
				break;
			case '2':
				System.out.println("Оператор switch:\n");
                                System.out.println("switch(условие) {");
                                System.out.println("	case константа:");
				System.out.println("	последовательность операторов");
                                System.out.println("	break;");
                                System.out.println("	...");
				System.out.println("}");
                                break;
			default:
				System.out.println("Неверный номер подраздела"); 

		}
	}
}
