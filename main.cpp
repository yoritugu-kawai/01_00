#include <Novice.h>
#include<Lp.h>
const char kWindowTitle[] = "LE2B_08_カワイヨリツグ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		//正射影
		Matrix4x4 orthographicMatrix = MakeOrthographicMatrix(-160.f, 160.f, 200.0f, 300.0f, 0.0f, 1000.0f);
		//同次クリップへ
		//透視投影
		Matrix4x4 perspectiveFovMatrix = MakePerspectiveFovMatrix(0.63f, 1.33f, 0.1f, 1000.0f);
		//いざスクリーンへ
		Matrix4x4 viewportMatrixMatrix = MakeViewportMatrix(100.0f, 200.0f, 600.0f, 300.0f, 0.0f, 1.0f);

		//同次クリップ空間(Homogeneous Clip Space)
		//範囲を切り取り正規化デバイス座標系へ変換
		//(-1,-1,0)~(1,1,1)


		//正射影行列



		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		MatrixScreenPrintf(0, ROW_HEIGHT * 5 * 0, orthographicMatrix, "orthographicMatrix");
		MatrixScreenPrintf(0, ROW_HEIGHT * 5 * 1, perspectiveFovMatrix, "perspectiveFovMatrix");
		MatrixScreenPrintf(0, ROW_HEIGHT * 5 * 2, viewportMatrixMatrix, "viewportMatrixMatrix");


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
