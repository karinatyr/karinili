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
	}
}
