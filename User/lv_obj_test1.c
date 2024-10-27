#include "lv_obj_test1.h"

#include "lvgl/lvgl.h"

#include <unistd.h>
#include <pthread.h>

void btn_pls_press_cb(lv_event_t * e)
{
    lv_obj_t *obj = (lv_obj_t *)e->user_data;

    int orig_width = lv_obj_get_width(obj);
    lv_obj_set_width( obj, orig_width + 10);
    lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);
}

void btn_min_press_cb(lv_event_t * e)
{
    lv_obj_t *obj = (lv_obj_t *)e->user_data;

    int orig_width = lv_obj_get_width(obj);
    lv_obj_set_width( obj, orig_width - 10);
    lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);
}

void lv_obj_test1(void)
{
    lv_obj_t *obj1 = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj1, 50, 50);

    lv_obj_align_to(obj1, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);

    lv_obj_t *btn1 = lv_button_create(lv_scr_act());
    lv_obj_set_pos(btn1, 0, 60);
    lv_obj_t *btn_lable = lv_label_create(btn1);
    lv_label_set_text(btn_lable, "+");
    lv_obj_add_event_cb(btn1, btn_pls_press_cb, LV_EVENT_PRESSED, (void *)obj1);
    lv_obj_align_to(btn1, obj1, LV_ALIGN_OUT_BOTTOM_MID, -50, 0);


    lv_obj_t *btn2 = lv_button_create(lv_scr_act());
    lv_obj_set_pos(btn2, 50, 60);
    lv_obj_t *btn_lable2 = lv_label_create(btn2);
    lv_label_set_text(btn_lable2, "-");
    lv_obj_add_event_cb(btn2, btn_min_press_cb, LV_EVENT_PRESSED, (void *)obj1);
    lv_obj_align_to(btn2, obj1, LV_ALIGN_OUT_BOTTOM_MID, +50, 0);
}
