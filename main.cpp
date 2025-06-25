#include <string>
#include <array>
#include <stdlib.h>
#include "ap_fixed.h"
#include "emulator.h"

int main()
{
  std::string modelName = "topo_v1";
  hls4mlEmulator::ModelLoader loader = hls4mlEmulator::ModelLoader(modelName);
  std::shared_ptr<hls4mlEmulator::Model> model = loader.load_model();
  
  //make sure these match your current model
  static const int N_INPUT_1_1 = 20;
  static const int N_LAYER_11 = 1;
  ap_fixed<16,6> modelInput[N_INPUT_1_1];
  ap_fixed<16,6> modelResult[N_LAYER_11];

  std::cout << "modelInput = [";

  for (int i = 0; i < N_INPUT_1_1; i++) {
    modelInput[i] = (rand() % 100) / 10.;
    std::cout << modelInput[i] << ", ";
  }
  std::cout << "]" << std::endl;
  
  for (int i = 0; i < N_LAYER_11; i++) {
    modelResult[i] = -1;
  }

  model->prepare_input(modelInput);
  model->predict();

  std::cout << "modelResult before read = [";
  for (int i = 0; i < 1; i++){
    std::cout << modelResult[i] << ", ";
  }
  std::cout << "]" << std::endl;

  std::cout << "reading result..." << std::endl;
  model->read_result(modelResult);
  std::cout << "DONE..." << std::endl;

  std::cout << "modelResult after read = [";
  for (int i = 0; i < 1; i++){
    std::cout << modelResult[i] << ", ";
  }
  std::cout << "]" << std::endl;

  return 0;
}
 