package controller;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.layout.AnchorPane;
import javafx.scene.shape.Rectangle;
import javafx.stage.FileChooser;
import model.ScheduleModel;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ScheduleController {

    // FXML Variable
    @FXML private Label _input;
    @FXML private Label _output;

    @FXML private Label _Makespan;
    @FXML private Label _WJCJ;
    @FXML private Label _WJFJ;
    @FXML private Label _WJTJ;

    @FXML private AnchorPane _diagram;

    // Choix de la structure et du modèle d'ordre
    @FXML private RadioButton _rOL;
    @FXML private RadioButton _rBST;
    @FXML private RadioButton _rEBST;
    @FXML private RadioButton _rSPT;
    @FXML private RadioButton _rLPT;
    @FXML private RadioButton _rWSPT;
    @FXML private RadioButton _rFCFS;

    // BackFilling
    @FXML private RadioButton _rbf;
    @FXML private RadioButton _rnbf;


    private ScheduleModel schedModel;

    public ScheduleController() {

    }

    public void initialize() {

    }

    // Setter
    private void SetModel(ScheduleModel schedModel) {
        this.schedModel = schedModel;
    }

    public void SetSchedule(String input, String output, int dt, int ord, int bf) {
        GetModel().getSchedule(input, output, dt, ord, bf);
    }

    // Getter
    private ScheduleModel GetModel() {
        return this.schedModel;
    }

    // SetInput
    @FXML
    public void SetInput() {
        FileChooser file = new FileChooser();
        file.setTitle("Selection du fichier entrant.");
        File selectedFile = file.showOpenDialog(null);
        this._input.setText(selectedFile.toString());
    }

    // Set Output
    @FXML
    public void SetOutput() {
        FileChooser file = new FileChooser();
        file.setTitle("Selection du fichier Sortant.");
        File selectedFile = file.showOpenDialog(null);
        this._output.setText(selectedFile.toString());
    }

    // Management of the Schedule data
    @FXML
    public void Exec_Schedule() {
        if (_rOL.isSelected()) {
            if (_rSPT.isSelected()) {
                if (_rbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 0, 0, 1);
                else if (_rnbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 0, 0, 0);            }
            else if (_rLPT.isSelected()) {
                if (_rbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 0, 1, 1);
                else if (_rnbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 0, 1, 0);
            }
            else if (_rWSPT.isSelected()) {
                if (_rbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 0, 2, 1);
                else if (_rnbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 0, 2, 0);
            }
            else if (_rFCFS.isSelected()) {
                if (_rbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 0, 3, 1);
                else if (_rnbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 0, 3, 0);
            }
        }
        else if (_rBST.isSelected()) {
            if (_rSPT.isSelected()) {
                if (_rbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 1, 0, 1);
                else if (_rnbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 1, 0, 0);            }
            else if (_rLPT.isSelected()) {
                if (_rbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 1, 1, 1);
                else if (_rnbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 1, 1, 0);
            }
            else if (_rWSPT.isSelected()) {
                if (_rbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 1, 2, 1);
                else if (_rnbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 1, 2, 0);
            }
            else if (_rFCFS.isSelected()) {
                if (_rbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 1, 3, 1);
                else if (_rnbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 1, 3, 0);
            }
        }
        else if (_rEBST.isSelected()) {
            if (_rSPT.isSelected()) {
                if (_rbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 2, 0, 1);
                else if (_rnbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 2, 0, 0);            }
            else if (_rLPT.isSelected()) {
                if (_rbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 2, 1, 1);
                else if (_rnbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 2, 1, 0);
            }
            else if (_rWSPT.isSelected()) {
                if (_rbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 2, 2, 1);
                else if (_rnbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 2, 2, 0);
            }
            else if (_rFCFS.isSelected()) {
                if (_rbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 2, 3, 1);
                else if (_rnbf.isSelected())
                    GetModel().getSchedule(_input.toString(), _output.toString(), 2, 3, 0);
            }
        }
    }

    // Diagram
    public void SetDiagram() {
        // Constant
        final int DEFAULT_MARGIN = 25;

        String path_output = this._output.toString();
        AnchorPane root = this._diagram;
        File file = new File(path_output);

        int y = 30; // Default Pos
        int nbr = 0; // Nb of rectangle

        try {
            Scanner reader = new Scanner(file);
            while(reader.hasNextLine()) {
                String [] data = reader.nextLine().split(" ");
                int start = StrToInt(data[2]);
                int end = StrToInt(data[3]);

                // Setup Rectangle
                Rectangle rec = new Rectangle(DEFAULT_MARGIN * (end - start), DEFAULT_MARGIN);
                rec.setLayoutX(DEFAULT_MARGIN * start);
                rec.setLayoutY(DEFAULT_MARGIN * (nbr + 1));

                // Add to diagram
                this._diagram.getChildren().add(rec);

            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private int StrToInt(String str) {
        return Integer.parseInt(str);
    }

}
