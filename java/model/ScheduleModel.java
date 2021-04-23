package model;

import java.io.File;

public class ScheduleModel {

    static {
        System.loadLibrary("schedulelibrary");
    }

    public ScheduleModel() {

    }

    public native void getSchedule(String inFileName, String outFileName, int datastructure, int order, int backfilling);

}
