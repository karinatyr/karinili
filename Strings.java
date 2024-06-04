class Strings {
	public static void main(String args[]){
		String str1 = "Первая строка";
		String str2 = new String(str1);
		String str3 = "Третья строка";
		int result, idx;
		char ch;
		
		System.out.println("Длина строки str1: " + str1.length());
		//посимвольный ввод строки на экран
		for(int i = 0; i < str1.length(); i++)
			System.out.println(str1.charAt(i));
		System.out.println();
		if(str1.equals(str2))
			System.out.println("str1 и str2 эквиалентны");
		else 
			System.out.println("str1 и str2 не эквиалентны");
		if(str1.equals(str3))
                        System.out.println("str1 и str3 эквиалентны");
                else
                        System.out.println("str1 и str3 не эквиалентны");
		result = str1.compareTo(str3);
		if(result == 0)
			System.out.println("str1 и str3 равны");
		else if(result < 0)
			System.out.println("str1 меньше, чем str3");
		else 
			System.out.println("str1 больше, чем str3");
		String str4 = "Строка для поиска подстроки. Значения: подстрока 1, подстрока 2, подстрока 3";
		idx = str4.indexOf("подстрока");
		System.out.println("Индекс первого вхождения слова \"подстрока\": " + idx);
		idx = str4.lastIndexOf("подстрока");
		System.out.println("Индекс последнего  вхождения слова \"подстрока\": " + idx); 	
	}
}	

	
