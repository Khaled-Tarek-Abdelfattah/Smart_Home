/*
 * Gpt_Pcfg.h
 *
 * Created: 10/12/2021 12:59:03 PM
 *  Author: hp
 */ 


#ifndef GPT_PCFG_H_
#define GPT_PCFG_H_

#define GPT_CHANNELS_NUM						    (3U)

#define TIMER0_CMPMATCH_INT_ENABLE					(1U)
#define TIMER0_OV_INT_ENABLE						(0U)

#define TIMER0_CMPMATCH_FLAG						(1U)
#define TIMER0_OV_FLAG								(0U)

#define TIMER1_OV_INT_ENABLE						(2U)
#define TIMER1_CMP_A_INT_ENABLE						(4U)
#define TIMER1_CMP_B_INT_ENABLE						(3U)

#define TIMER1_OV_FLAG								(2U)
#define TIMER1_CMP_A_FLAG							(4U)
#define TIMER1_CMP_B_FLAG							(3U)

#define TIMER2_OV_INT_ENABLE						(6U)
#define TIMER2_CMPMATCH_INT_ENABLE					(7U)

#define TIMER2_OV_FLAG								(6U)
#define TIMER2_CMPMATCH_FLAG						(7U)
#endif /* GPT_PCFG_H_ */