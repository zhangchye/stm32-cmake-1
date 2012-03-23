#include <stm32f4xx_tim.h>

#include "stm32f4xx_it.h"

#include "control.h"

void TIM6_DAC_IRQHandler(void ) {
  if (TIM_GetITStatus(TIM6, TIM_IT_Update) != RESET) {
    /* Очищаем бит обрабатываемого прерывания */
    TIM_ClearITPendingBit(TIM6, TIM_IT_Update);
    Contjrol contrl;
    contrl.setState(contrl.getNextState());
  }
  TIM13->PSC = 1000 - 1;
}
