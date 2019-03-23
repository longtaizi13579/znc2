/*******************************************************************************
函数名称：get_vline
函数功能: 得到有效行
参数：无
*******************************************************************************/
void get_vline()
{
  if(Shi_zi_num==0)
  {
	valid_line=judge_vl;
  }
  else 
  {
	valid_line=55;
  }
}
/*******************************************************************************
函数名称：clearDelPar
函数功能: 清零处理参数
参数：无
*******************************************************************************/
void clearDelPar()
{
 	startline_F=0;//发现起始行标志清0
 	//endline_F=0;//发现结束行标志清0
	//PickCenter_flag=0;//清零图像开始寻黑线标志
	lost_already=0;
	Lost_Line_count=0;
	Lost_left_count=0;
	Lost_right_count=0;
	Pick_line=0;
	Shi_zi_line=0;
	Bline_diff=0;
	maxBline_diff=0;
	Shi_zi_flag=0;
	lost_w_count=0;
	lost_b_count=0;
	near_xielv_left=0;
	near_xielv_right=0;
}
/*******************************************************************************
函数名称：stable_del
函数功能: 数据处理控制程序
参数：无
*******************************************************************************/
void stable_del()
{
  	uint8 line;
	if(run_time==100)//采集图像两百次后启动电机（延时）,不知道多少次，需延时。
	{
	  	enable_pit_int(PIT1);//开启PIT1中断
	}
////////////////////////////////////////////////////////////////////////////////
	buzzer_ctl();
	get_vline();//得到有效行
	xielv_lvbo();//跳变差值限制法滤波 去除无效行
	lvbo(5);
   	ti_jiaozheng();
	bDistance();//赛道宽度法滤波 去除无效行
   	/*for(line=0;line<H;line++)
	{
	  Pick_table[line]=(Bline_left[line]+Bline_right[line])/2;//
	}
	*/
	getBlineCenter();
	averageLvBo();
	//center_led();
	center_buxian();
	{
	  positive_num=0;
	  decrease_num=0;
	  for(line=1;line<valid_line;line++)
	  {
		if(Pick_table[line]>Pick_table[line-1])
		  positive_num++;
		else if(Pick_table[line]<Pick_table[line-1])
		  decrease_num++;
	  }
	}
	//put_get_hex_whole(Pick_table,Bline_left,Bline_right,H);  
	if(run_time>100)
	{
		Is_out();
	    //Out_flag=0;
		if(Out_flag==1)
		{
		  GPIOB_PDOR &= ~ GPIO_PDOR_PDO(GPIO_PIN(17));/// 无效图像指示灯亮 LED4
		  jiaodu_num=last_turn;
		  slow_down_num=1;
		  //find_shizi(valid_line);
		  way_control();
		  /*if(start_end_flag==1)//如果发现起跑线标志，则停车
			stop_car();
		  else*/
		  	//speed_ctl_stable();
		  stop_num++;
		  if(stop_num>5)
		  stop_car();
		  if(run_time>500)
				test_start_new();
		}
		else
		{
		    GPIOB_PDOR |=  GPIO_PDOR_PDO(GPIO_PIN(17));	//IO口输出亮高电平 LED4
			//find_s();
			//area=get_area(Pick_table[5],Pick_table[(valid_line)/2],Pick_table[valid_line],5,(valid_line)/2,valid_line);
			//lcd_int(8,"Xl:",(int)area);
			get_LR_diff();
			//If_straight();//判断是否为直道
			judgeRoad();//判断赛道类型
			//zhidao_count_flag=0;
			//lost_count();//计算丢失行
			if(valid_line>10)
			Position_diff=Pick_table[10]-last_position;
			last_position=Pick_table[10];
			whole_area=getWholeArea();
			tx_area=getTxArea();
			get_even_diff_s();
			get_even_diff_near();
			If_LStraight();
			//find_S_road();
			//get_Curve_whole();
			//get_Curve();
			//if(Near_lost==0)
			seg_pid_stable();
			way_control();
			//servo_ctl();
			last_vline=valid_line;
/////////////////////////////////速度控制/////////////////////////////////
			/*if(start_end_flag==1)//如果发现起跑线标志，则停车
			{
			  	stop_car();
			}
			else*/
			if(FRONT>1500&&Bmq<5)//防撞车 最后得去除
			{
				ideal_Bmq=1;
			}
			else 
				speed_ctl_stable();
			if(run_time>500)
				test_start_new();
		}
	}
}
/*******************************************************************************
函数名称：deal_ctrl
函数功能: 数据处理控制
参数：无
*******************************************************************************/
void deal_ctrl()
{
    uint8 line;
	buzzer_ctl();
	lvbo(5);
    for(line=0;line<H;line++)
        Pick_table[line]=(Bline_left[line]+Bline_right[line])/2;
	center_led();
	center_buxian();
	if(run_time==200)//采集图像两百次后启动电机（延时）
	{
	  	enable_pit_int(PIT1);//开启PIT1中断
	}
		Is_out();
		if(Out_flag==1)
		{
		  GPIOB_PDOR &= ~ GPIO_PDOR_PDO(GPIO_PIN(2));///无效图像指示灯亮
			jiaodu_num=last_turn;
		  slow_down_num=1;
		  way_control();
		  if(start_end_flag==1)//如果发现起跑线标志，则停车
			stop_car();
		  else if(FTM2_C0V>4000&&Bmq<10)//防撞车 最后得去除
			{
			  ideal_Bmq=0;
			}
		  else
		  	speed_ctl();
		}
		else
		{
		    GPIOB_PDOR |=  GPIO_PDOR_PDO(GPIO_PIN(2));	//IO口输出亮高电平
			
			get_vl_new1();
			saidao_judge_new();
			if(run_time>500)
				test_start_new();
			If_straight_new();
			get_even_diff();
			seg_pid(); 
			//pick_way=1; 

			way_control();
			if(start_end_flag==1)//如果发现起跑线标志，则停车
			  stop_car();
			else if(FTM2_C0V>4000&&Bmq<10)//防撞车 最后得去除
			{
			  ideal_Bmq=0;
			}
			else 
			  speed_ctl();	
		}
}
/*******************************************************************************
函数名称：lvbo
函数功能: 滤波
参数：
*******************************************************************************/
void lvbo(uint8 num)
{
  uint8 line;
  for(line=4;line<50;line++)
  {
	if((Bline_left[line]>Bline_left[line-1])&&(Bline_left[line]>Bline_left[line+1]))
	{
	  if(((Bline_left[line]-Bline_left[line-1])>num)
		 &&((Bline_left[line]-Bline_left[line+1])>num))
	  
	  {
	  	Bline_left[line]=(Bline_left[line-1]+Bline_left[line+1])/2;
	  }
	}
	else if((Bline_left[line]<Bline_left[line-1])&&(Bline_left[line]<Bline_left[line+1]))
    {
	 if(((Bline_left[line-1]-Bline_left[line])>num)
			 &&((Bline_left[line+1]-Bline_left[line])>num))
	  {
			Bline_left[line]=(Bline_left[line-1]+Bline_left[line+1])/2;
	   }
	}
	
	if((Bline_right[line]>Bline_right[line-1])&&(Bline_right[line]>Bline_right[line+1]))
	{
	  if(((Bline_right[line]-Bline_right[line-1])>num)
		 &&((Bline_right[line]-Bline_right[line+1])>num))
	  
	  {
		Bline_right[line]=(Bline_right[line-1]+Bline_right[line+1])/2;
	  }
	}
	else if((Bline_right[line]<Bline_right[line-1])&&(Bline_right[line]<Bline_right[line+1]))
    {
	 if(((Bline_right[line-1]-Bline_right[line])>num)
			 &&((Bline_right[line+1]-Bline_right[line])>num))
	  {
			Bline_right[line]=(Bline_right[line-1]+Bline_right[line+1])/2;
	   }
	}
  }
}
/*******************************************************************************
函数名称：center_buxian
函数功能: 滤波
参数：
*******************************************************************************/
void center_buxian()
{
  uint8 line;
  for(line=3;line<50;line++)
  {
	if((Pick_table[line]>Pick_table[line-1])&&(Pick_table[line]>Pick_table[line+1]))
	{
		Pick_table[line]=(Pick_table[line-1]+Pick_table[line+1])/2;
	}
	else if((Pick_table[line]<Pick_table[line-1])&&(Pick_table[line]<Pick_table[line+1]))
	{
		Pick_table[line]=(Pick_table[line-1]+Pick_table[line+1])/2; 
	}
  }
}
