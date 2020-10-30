int max_stu_cla(int p[10][5])
{
	int i, j, max = 1;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (max < p[i][j])
			{
				max = p[i][j];
			}
		}
	}
	return max;
}