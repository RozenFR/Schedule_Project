package controller;

import model.ScheduleModel;

public class ScheduleController {

    private ScheduleModel schedModel;

    public ScheduleController(ScheduleModel schedModel) {
        SetModel(schedModel);
    }

    // Setter
    private void SetModel(ScheduleModel schedModel) {
        this.schedModel = schedModel;
    }

    public void SetSchedule(String input, String output, int dt, int ord, int bf) {
        GetModel().getSchedule(input, output, dt, ord, bf);
    }

    // Getter
    public ScheduleModel GetModel() {
        return this.schedModel;
    }

}
