/*******************************************************************************
�������ƣ�get_vline
��������: �õ���Ч��
��������
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
�������ƣ�clearDelPar
��������: ���㴦�����
��������
*******************************************************************************/
void clearDelPar()
{
 	startline_F=0;//������ʼ�б�־��0
 	//endline_F=0;//���ֽ����б�־��0
	//PickCenter_flag=0;//����ͼ��ʼѰ���߱�־
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
�������ƣ�stable_del
��������: ���ݴ�����Ƴ���
��������
*******************************************************************************/
void stable_del()
{
  	uint8 line;
	if(run_time==100)//�ɼ�ͼ�����ٴκ������������ʱ��,��֪�����ٴΣ�����ʱ��
	{
	  	enable_pit_int(PIT1);//����PIT1�ж�
	}
////////////////////////////////////////////////////////////////////////////////
	buzzer_ctl();
	get_vline();//�õ���Ч��
	xielv_lvbo();//�����ֵ���Ʒ��˲� ȥ����Ч��
	lvbo(5);
   	ti_jiaozheng();
	bDistance();//������ȷ��˲� ȥ����Ч��
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
		  GPIOB_PDOR &= ~ GPIO_PDOR_PDO(GPIO_PIN(17));/// ��Чͼ��ָʾ���� LED4
		  jiaodu_num=last_turn;
		  slow_down_num=1;
		  //find_shizi(valid_line);
		  way_control();
		  /*if(start_end_flag==1)//������������߱�־����ͣ��
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
		    GPIOB_PDOR |=  GPIO_PDOR_PDO(GPIO_PIN(17));	//IO��������ߵ�ƽ LED4
			//find_s();
			//area=get_area(Pick_table[5],Pick_table[(valid_line)/2],Pick_table[valid_line],5,(valid_line)/2,valid_line);
			//lcd_int(8,"Xl:",(int)area);
			get_LR_diff();
			//If_straight();//�ж��Ƿ�Ϊֱ��
			judgeRoad();//�ж���������
			//zhidao_count_flag=0;
			//lost_count();//���㶪ʧ��
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
/////////////////////////////////�ٶȿ���/////////////////////////////////
			/*if(start_end_flag==1)//������������߱�־����ͣ��
			{
			  	stop_car();
			}
			else*/
			if(FRONT>1500&&Bmq<5)//��ײ�� ����ȥ��
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
�������ƣ�deal_ctrl
��������: ���ݴ������
��������
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
	if(run_time==200)//�ɼ�ͼ�����ٴκ������������ʱ��
	{
	  	enable_pit_int(PIT1);//����PIT1�ж�
	}
		Is_out();
		if(Out_flag==1)
		{
		  GPIOB_PDOR &= ~ GPIO_PDOR_PDO(GPIO_PIN(2));///��Чͼ��ָʾ����
			jiaodu_num=last_turn;
		  slow_down_num=1;
		  way_control();
		  if(start_end_flag==1)//������������߱�־����ͣ��
			stop_car();
		  else if(FTM2_C0V>4000&&Bmq<10)//��ײ�� ����ȥ��
			{
			  ideal_Bmq=0;
			}
		  else
		  	speed_ctl();
		}
		else
		{
		    GPIOB_PDOR |=  GPIO_PDOR_PDO(GPIO_PIN(2));	//IO��������ߵ�ƽ
			
			get_vl_new1();
			saidao_judge_new();
			if(run_time>500)
				test_start_new();
			If_straight_new();
			get_even_diff();
			seg_pid(); 
			//pick_way=1; 

			way_control();
			if(start_end_flag==1)//������������߱�־����ͣ��
			  stop_car();
			else if(FTM2_C0V>4000&&Bmq<10)//��ײ�� ����ȥ��
			{
			  ideal_Bmq=0;
			}
			else 
			  speed_ctl();	
		}
}
/*******************************************************************************
�������ƣ�lvbo
��������: �˲�
������
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
�������ƣ�center_buxian
��������: �˲�
������
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
