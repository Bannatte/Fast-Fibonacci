int div_sqrt_five (int num)
{
  int low = num / 3;
  int upp = num / 2;

  int target = num * num;
  while (low <= upp) 
  {
    int mid = (low + upp) / 2;
    int value = 5 * mid * mid;

    if (value == target) {
      return mid;
    } else if (value < target) {
      low = mid + 1;
    } else {
      upp = mid - 1;
    }
  }

  return upp;
}

int fast_fib (int num) {
  int highest_bit = 31;
  while (((num >> highest_bit) & 1) == 0) {
    highest_bit--;
  }

  int p_array[highest_bit];
  p_array[0] = 1;
  int q_array[highest_bit];
  q_array[0] = 1;

  for (int i = 0; i <= highest_bit; i++) {
    p_array[i+1] = p_array[i] * p_array[i] + 5 * q_array[i] * q_array[i];
    q_array[i+1] = 2 * p_array[i] * q_array[i];
  }
  
  int p_tot = 1;
  int q_tot = 0;
  for (int j = highest_bit; 0 <= j; j--) {
    int b = (num >> i) & 1;

    if (b == 0) {
      continue;
    }

    int p_tot_new = p_array[j] * p_tot + q_array[j] * q_tot * 5;
    q_tot = q_array[j] * p_tot + p_array[j] * q_tot;
    p_tot = p_tot_new;
  }

  int fib = (div_sqrt_five(p_tot) + q_tot) >> num;

  if (num % 2 == 1) {
    fib++;
  }

  return fib;
}
