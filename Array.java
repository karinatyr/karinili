class Array {
	public static void main(String args[]){
		//Создание одномерного массива и вывод значений на экран 
		int nums[] = new int[10];
		int i;
		for(i = 0; i < 10; i++)
			nums[i] = i;
		for(i = 0; i < 10; i++)
			System.out.println("Элемент ["+ i + "]: " +nums[i]);
		//Альтернативный способ инициализации массива
		int nums2[] = {99, 55, 612, -46, 256, 32, 65, 69, 20, 50, 563, 23, 156, 56, 89};

		int min,max;
		//поиск мин и макс значенией 
		min = max = nums2[0];
		for (i = 1; i < nums2.length; i++){
			if(nums2[i] < min) min = nums2[i];
			if(nums2[i] > max) max = nums2[i];
		}


		System.out.println("Минимальное значение в массиве: " + min + "\n Максимальное значние в массиве: " + max);
		// Пузырьковая сортировка массива nums2
		int a, b, t;
		int size = nums2.length;
		System.out.println("Массив до сортировки: ");
		for (i= 0; i < size; i++)
			System.out.println(" " + nums2[i]);
		System.out.println();
		
		for (a= 1; a < size; a++)
			for (b= size-1; b >= a; b--){
				if(nums2[b-1] > nums2[b]){
					t = nums2[b-1];
					nums2[b-1] = nums2[b];
					nums2[b] = t;
				}
			}

		System.out.println("Массив после сортировки");
		for (i= 0; i < size; i++)
                        System.out.println(" " + nums2[i]);
		//использование прееменной экземпляра length
		System.out.println("Размер nums: " + nums.length);
		System.out.println("Размер nums2: " + nums2.length);
		for (i = 0; i < nums2.length; i++)
			System.out.println(nums2[i]);
	}
}

