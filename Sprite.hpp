class Sprite{
    public:
        Sprite();
        Sprite(float x, float y);
        Sprite(float x, float y, float width, float height);
        void Draw();
    private:
        float x, y, height, width;
        spMatrixStack transform;
};
