#include"TetrisData.h"
using namespace data;

pos_array_type mov_box_type::toArray() const
{
	pos_array_type array = {{0,0,0,0},{0,0,0,0}};
	switch(type)
	{
		case box::O:
		{
			char xx[] = {1,2,1,2};
			char yy[] = {0,0,1,1};
			for(int i=0; i<4;i++)
			{

				array.x[i] = xx[i] + x;
				array.y[i] = yy[i] + y;
			}
			break;
		}
		case box::I:
		{
			switch(direction) 
			{

				case 0:case 2: 
				{
					char xx[] = {1,1,1,1};
					char yy[] = {0,1,2,3};
					for(int i=0; i<4;i++)
					{

						array.x[i] = xx[i] + x;
						array.y[i] = yy[i] + y;	
					}
					break; 
				}
				case 1:case 3:
				{
					char xx[] = {0,1,2,3};
					char yy[] = {1,1,1,1};
					for(int i=0; i<4;i++)
					{

						array.x[i] = xx[i] + x;
						array.y[i] = yy[i] + y;	
					}
					break;

				}
				default:break;
			}
			break;
		}
		case box::Z:
		{

			switch(direction)
			{

				case 0:case 2:
				{
					char xx[] = {1,2,0,1};
					char yy[] = {0,0,1,1};
					for(int i=0; i<4;i++)
					{

						array.x[i] = xx[i] + x;
						array.y[i] = yy[i] + y;	
					}
					break;
				}
				case 1:case 3:
				{
					char xx[] = {0,1,0,1};
					char yy[] = {0,1,1,2};
					for(int i=0; i<4;i++)
					{

						array.x[i] = xx[i] + x;
						array.y[i] = yy[i] + y;	
					}
					break;

				}
				default:break;
			}
			break;
		}	
	case box::S:
	{
		switch(direction)
			{

				case 0:case 2:
				{
					char xx[] = {0,1,1,2};
					char yy[] = {0,0,1,1};
					for(int i=0; i<4;i++)
					{

						array.x[i] = xx[i] + x;
						array.y[i] = yy[i] + y;	
					}
					break;
				}
				case 1:case 3:
				{
					char xx[] = {2,1,2,1};
					char yy[] = {0,1,1,2};
					for(int i=0; i<4;i++)
					{

						array.x[i] = xx[i] + x;
						array.y[i] = yy[i] + y;	
					}
					break;

				}
				default:break;
			}
		break;
	}
	case box::T:
	{
		switch(direction)
			{
				case 2:
				{
					char xx[] = {0,1,2,1};
					char yy[] = {1,1,1,2};
					for(int i=0; i<4;i++)
					{

						array.x[i] = xx[i] + x;
						array.y[i] = yy[i] + y;	
					}
					break;
				}
				case 3:
				{
					char xx[] = {1,1,2,1};
					char yy[] = {0,1,1,2};
					for(int i=0; i<4;i++)
					{

						array.x[i] = xx[i] + x;
						array.y[i] = yy[i] + y;	
					}
					break;
				}
				case 0:
				{
					char xx[] = {1,0,1,2};
					char yy[] = {0,1,1,1};
					for(int i=0; i<4;i++)
					{

						array.x[i] = xx[i] + x;
						array.y[i] = yy[i] + y;	
					}
					break;

				}
				case 1:
				{
					char xx[] = {1,0,1,1};
					char yy[] = {0,1,1,2};
					for(int i=0; i<4;i++)
					{

						array.x[i] = xx[i] + x;
						array.y[i] = yy[i] + y;	
					}
					break;
				}
				default:break;
			}
		break;
	}
	case box::J:
	{
		switch(direction)
			{
				case 0:
				{
					char xx[] = {0,1,1,1};
					char yy[] = {0,0,1,2};
					for(int i=0; i<4;i++)
					{

						array.x[i] = xx[i] + x;
						array.y[i] = yy[i] + y;	
					}
					break;
				}
				case 1:
				{
					char xx[] = {0,1,2,0};
					char yy[] = {1,1,1,2};
					for(int i=0; i<4;i++)
					{

						array.x[i] = xx[i] + x;
						array.y[i] = yy[i] + y;	
					}
					break;
				}
				case 2:
				{
					char xx[] = {1,1,1,2};
					char yy[] = {0,1,2,2};
					for(int i=0; i<4;i++)
					{

						array.x[i] = xx[i] + x;
						array.y[i] = yy[i] + y;	
					}
					break;

				}
				case 3:
				{
					char xx[] = {0,1,2,2};
					char yy[] = {0,1,1,1};
					for(int i=0; i<4;i++)
					{

						array.x[i] = xx[i] + x;
						array.y[i] = yy[i] + y;	
					}
					break;
				}
				default:break;
			}
		break;
	}
	case box::L:
	{
		switch(direction)
			{
				case 0:
				{
					char xx[] = {1,2,1,1};
					char yy[] = {0,0,1,2};
					for(int i=0; i<4;i++)
					{

						array.x[i] = xx[i] + x;
						array.y[i] = yy[i] + y;	
					}
					break;
				}
				case 1:
				{
					char xx[] = {0,0,1,2};
					char yy[] = {0,1,1,1};
					for(int i=0; i<4;i++)
					{

						array.x[i] = xx[i] + x;
						array.y[i] = yy[i] + y;	
					}
					break;
				}
				case 2:
				{
					char xx[] = {1,1,0,1};
					char yy[] = {0,1,2,2};
					for(int i=0; i<4;i++)
					{

						array.x[i] = xx[i] + x;
						array.y[i] = yy[i] + y;	
					}
					break;

				}
				case 3:
				{
					char xx[] = {0,1,2,2};
					char yy[] = {1,1,1,2};
					for(int i=0; i<4;i++)
					{

						array.x[i] = xx[i] + x;
						array.y[i] = yy[i] + y;	
					}
					break;
				}
				default:break;
			}
		break;
	}
	default:break;
	}
	return array;
}
