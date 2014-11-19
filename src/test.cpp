#include <iostream>
#include "base/matrix.hpp"
#include "base/data.hpp"
#include "core/registrator.hpp"
#include "core/cpd_rigid.hpp"
#include "core/cpd_nonrigid.hpp"
#include "fast/low_rank.hpp"

using namespace cpd;

using namespace Eigen;
using namespace std;

int main()
{

    MatrixType<float, 2>::MatrixD model, data;
    getInputData<float, 2>("y.txt", "x.txt", model, data);
    //getInputData<float, 3>("lily-5.txt", "lily-30.txt", model, data);

    CPDRigid<float, 2>* reg = new CPDRigid<float, 2>();
    reg->setInputData(model, data);
    reg->setVision(true);
    reg->setIterativeNumber(100);
    reg->setVarianceTolerance(1e-4);
    reg->setEnergyTolerance(1e-4);
    reg->setOutlierWeight(0.4);
    reg->setFgtFlag(true);
    reg->setFgtEpsilon(1e-4);
    /*reg->setLowRankFlag(true);
    reg->setKLowRank(30);*/
    reg->run();

    MatrixType<float, 2>::Matrix corres = reg->getCorrespondences();

    /*RenderThread<double, 3>::instance()->updateModel(reg->getModel());
    RenderThread<double, 3>::instance()->updateData(data);
    RenderThread<double, 3>::instance()->startThread();*/

    std::cout << reg->getModel() << std::endl;

    /*std::cout << "results:" << std::endl;
    std::cout << "model:" << std::endl;
    std::cout << reg->getModel() << std::endl;
    std::cout << "data:" << std::endl;
    std::cout << reg->getData() << std::endl;*/

    /*Eigen::Matrix<float, 3, 2, Eigen::RowMajor> a;
    Eigen::Matrix<float, 2, 3, Eigen::ColMajor> b;
    Eigen::Matrix<float, 2, 3, Eigen::RowMajor> c;

    a << 1,2,3,4,5,6;

    b << 1,2,
        3,4,
        5,6;

    c = b;

    c = Eigen::Matrix<float, 2, 3, Eigen::ColMajor>(c);

    std::cout << a << std::endl << std::endl;
    std::cout << b << std::endl << std::endl;
    std::cout << c << std::endl << std::endl;
    std::cout << *(a.data()+1) << std::endl << std::endl;
    std::cout << *(b.data()+1) << std::endl << std::endl;
    std::cout << a*b << std::endl << std::endl;
    std::cout << *(c.data()+1) << std::endl << std::endl;
    std::cout << *(Eigen::Matrix<float, 2, 3, Eigen::ColMajor>(c).data()+1) << std::endl << std::endl;*/

    /*double a[] = {0.1,0.1,0.2,0.3};
    float* b = (float*)a;

    std::cout << a[0] << std::endl;
    std::cout << b[0] << std::endl;*/
    //MatrixType<double, 3>::Matrix& G = reg->getG();
    //MatrixXd A = G;
    /*A << 1,4,2,
        4,2,1,
        2,1,1;*/
    //cout << "Here is a random 6x6 matrix, A:" << endl << A << endl << endl;
    //EigenSolver<MatrixXd> es(A);
    //cout << "The eigenvalues of A are:" << endl << es.eigenvalues() << endl;
    /*cout << "The matrix of eigenvectors, V, is:" << endl << es.eigenvectors() << endl << endl;
    complex<double> lambda = es.eigenvalues()[0];
    cout << "Consider the first eigenvalue, lambda = " << lambda << endl;
    VectorXcd v = es.eigenvectors().col(0);
    cout << "If v is the corresponding eigenvector, then lambda * v = " << endl << lambda * v << endl;
    cout << "... and A * v = " << endl << A.cast<complex<double> >() * v << endl << endl;
    MatrixXcd D = es.eigenvalues().asDiagonal();
    MatrixXcd V = es.eigenvectors();
    cout << "Finally, V * D * V^(-1) = " << endl << V * D * V.inverse() << endl;*/

    /*MatrixType<double, 2>::Matrix G = A;
    MatrixType<double, 2>::Matrix Q, S;
    int K = 2;
    lr_approximate<double, 2>(G, Q, S, K);
    std::cout << Q << std::endl;
    std::cout << S << std::endl;*/

}