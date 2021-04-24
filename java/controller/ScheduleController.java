package controller;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.StackPane;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Text;
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

    // Variable
    private ScheduleModel schedModel;

    public ScheduleController() {
    }

    @FXML
    public void initialize() {

    }

    // Setter
    private void SetSchedule(String input, String output, int dt, int ord, int bf) {
        new ScheduleModel().getSchedule(input, output, dt, ord, bf);
    }

    // Getter

    // SetInput
    @FXML
    public void SetInput() {
        FileChooser file = new FileChooser();
        file.setTitle("Selection du fichier entrant.");
        File selectedFile = file.showOpenDialog(null);
        if (selectedFile != null)
            this._input.setText(selectedFile.toString());
    }

    // Set Output
    @FXML
    public void SetOutput() {
        FileChooser file = new FileChooser();
        file.setTitle("Selection du fichier Sortant.");
        File selectedFile = file.showOpenDialog(null);
        if (selectedFile != null)
            this._output.setText(selectedFile.toString());

        try {
            Exec_Schedule();
            SetMakeSpan();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    // Management of the Schedule data
    @FXML
    public void Exec_Schedule() throws Exception {
        CleanDiagram();
        if (this._input.toString().isBlank())
            throw new NullPointerException("Exec_Schedule() : Input Path is not nullable");
        if (this._output.toString().isBlank())
            throw new NullPointerException("Exec_Schedule() : Output Path is not nullable");

        if (_rOL.isSelected()) {
            if (_rSPT.isSelected()) {
                if (_rbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 0, 0, 1);
                else if (_rnbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 0, 0, 0);
                else
                    throw new Exception("Exec_Schedule() OLSPT : Selection out of range.");}
            else if (_rLPT.isSelected()) {
                if (_rbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 0, 1, 1);
                else if (_rnbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 0, 1, 0);
                else
                    throw new Exception("Exec_Schedule() OLLPT : Selection out of range.");
            }
            else if (_rWSPT.isSelected()) {
                if (_rbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 0, 2, 1);
                else if (_rnbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 0, 2, 0);
                else
                    throw new Exception("Exec_Schedule() OLWSPT : Selection out of range.");
            }
            else if (_rFCFS.isSelected()) {
                if (_rbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 0, 3, 1);
                else if (_rnbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 0, 3, 0);
                else
                    throw new Exception("Exec_Schedule() OLFCFS : Selection out of range.");
            }
            else
                throw new Exception("Exec_Schedule() OL : Selection out of range.");
        }
        else if (_rBST.isSelected()) {
            if (_rSPT.isSelected()) {
                if (_rbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 1, 0, 1);
                else if (_rnbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 1, 0, 0);
                else
                    throw new Exception("Exec_Schedule() BSTSPT : Selection out of range.");}
            else if (_rLPT.isSelected()) {
                if (_rbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 1, 1, 1);
                else if (_rnbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 1, 1, 0);
                else
                    throw new Exception("Exec_Schedule() BSTLPT : Selection out of range.");
            }
            else if (_rWSPT.isSelected()) {
                if (_rbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 1, 2, 1);
                else if (_rnbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 1, 2, 0);
                else
                    throw new Exception("Exec_Schedule() BSTWSPT : Selection out of range.");
            }
            else if (_rFCFS.isSelected()) {
                if (_rbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 1, 3, 1);
                else if (_rnbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 1, 3, 0);
                else
                    throw new Exception("Exec_Schedule() BSTFCFS : Selection out of range.");
            }
            else
                throw new Exception("Exec_Schedule() BST : Selection out of range.");
        }
        else if (_rEBST.isSelected()) {
            if (_rSPT.isSelected()) {
                if (_rbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 2, 0, 1);
                else if (_rnbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 2, 0, 0);
                else
                    throw new Exception("Exec_Schedule() EBSTSPT : Selection out of range.");
            }
            else if (_rLPT.isSelected()) {
                if (_rbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 2, 1, 1);
                else if (_rnbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 2, 1, 0);
                else
                    throw new Exception("Exec_Schedule() EBSTLPT : Selection out of range.");
            }
            else if (_rWSPT.isSelected()) {
                if (_rbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 2, 2, 1);
                else if (_rnbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 2, 2, 0);
                else
                    throw new Exception("Exec_Schedule() EBSTWSPT : Selection out of range.");
            }
            else if (_rFCFS.isSelected()) {
                if (_rbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 2, 3, 1);
                else if (_rnbf.isSelected())
                    SetSchedule(this._input.toString(), this._output.toString(), 2, 3, 0);
                else
                    throw new Exception("Exec_Schedule() EBSTFCFS : Selection out of range.");
            }
            else
                throw new Exception("Exec_Schedule() EBST : Selection out of range.");
        }
        else
            throw new Exception("Exec_Schedule() ALL : Selection out of range.");

        SetDiagram();

        try {
            SetMakeSpan();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    // Diagram
    private void SetDiagram() throws Exception {
        // Constant
        final int DEFAULT_MARGIN = 25;

        // Variable
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
                StackPane stack = new StackPane();
                Text txt = new Text(data[0]);
                Rectangle rec = new Rectangle(DEFAULT_MARGIN * (end - start), DEFAULT_MARGIN);
                stack.getChildren().addAll(rec, txt);
                stack.setLayoutX(DEFAULT_MARGIN * start);
                stack.setLayoutY(DEFAULT_MARGIN * (nbr + 1));

                // Add to diagram
                this._diagram.getChildren().add(stack);

            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void CleanDiagram() {
        this._diagram.getChildren().clear();
    }

    private void SetMakeSpan() throws Exception {
        if (this._output.toString().isBlank()) {

            File file = new File(this._output.toString());
            int makespan = 0;

            try {

                Scanner reader = new Scanner(file);
                while (reader.hasNextLine()) {
                    String[] data = reader.nextLine().split(" ");
                    makespan = makespan + StrToInt(data[1]);
                }
                this._Makespan.setText(IntToStr(makespan));

            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }

        }
        else
            throw new Exception("ScheduleController <SetMakeSpan> : _output undefined.");
    }

    private int StrToInt(String str) throws Exception {
        if (str.isEmpty())
            throw new NullPointerException("StrToInt : str is not nullable.");
        if (str.contains("-"))
            throw new Exception("StrToInt : Conversion only available for positive value.");
        return Integer.parseInt(str);
    }

    private String IntToStr(int i) {
        return Integer.toString(i);
    }

}
