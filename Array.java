class Array {
	public static void main(String args[]){
		//Создание одномерного массива и вывод значений на экран 
		int nums[] = new int[10];
		int i;
		for(i = 0; i < 10; i++)
			nums[i] = 1;
		for(i = 0; i < 10; i++)
			System.out.println("Элемент ["+ i + "]: " +nums[i]);

	}
}

