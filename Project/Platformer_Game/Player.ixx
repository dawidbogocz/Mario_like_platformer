//module;
//
//#include <iostream>
//#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//
//export module Player;
//
//export enum ANIMATION_STATE {
//	IDLE = 0,
//	LEFT,
//	RIGHT,
//	JUMPRIGHT,
//	JUMPLEFT,
//	FALL
//};
//export class Player {
//private:
//	sf::Sprite sprite;
//	sf::Texture idle;
//
//	//Animation
//	sf::Clock Timer;
//	short state;
//	sf::IntRect Frame;
//	bool aSwitch;
//
//	//Physics
//	sf::Vector2f vel;
//	float maxVel;
//	float minVel;
//	float acc;
//	float dec;
//	float gravity;
//	float gravityMax;
//	float jumpHeight;
//	float canJump;
//	float isJumping;
//	float deltaTime;
//	void initPhysics();
//
//	void initVariable();
//	void initTexture();
//	void initSprite();
//	void initAnimation();
//
//public:
//	Player();
//	const bool& getAnimation();
//	const sf::Vector2f getPosition() const;
//
//	void setPosition(const float x, const float y);
//
//	//Functions
//	void animationTimer();
//	void updateMovement();
//	void updateAnimation();
//	void update();
//	void render(sf::RenderTarget& target);
//};
//
//void Player::initPhysics()
//{
//	this->acc = 400.f;
//	this->jumpHeight = 150.f;
//	this->canJump = true;
//	this->isJumping = false;
//}
//
//void Player::initVariable()
//{
//	this->state = ANIMATION_STATE::IDLE;
//}
//
//void Player::initTexture()
//{
//	if (!this->idle.loadFromFile("Textures/herochar.png")) {
//		std::cout << "ERROR::PLAYER::Could not load the player sheet!" << std::endl;
//	}
//}
//
//void Player::initSprite()
//{
//	this->sprite.setTexture(this->idle);
//	this->Frame = sf::IntRect(0, 0, 32, 32);
//	this->sprite.setTextureRect(this->Frame);
//	this->sprite.setScale(2.f, 2.f);
//	this->deltaTime = Timer.restart().asSeconds();
//	this->sprite.setOrigin(16.f, 16.f);
//	this->sprite.setPosition(0, 300);
//	
//}
//
//void Player::initAnimation()
//{
//	this->Timer.restart();
//	this->aSwitch = true;
//}
//
//Player::Player()
//{
//	this->initVariable();
//	this->initTexture();
//	this->initSprite();
//	this->initAnimation();
//	this->initPhysics();
//}
//
//const bool& Player::getAnimation()
//{
//	bool tmp = this->aSwitch;
//	if (this->aSwitch) {
//		this->aSwitch = false;
//	}
//	return tmp;
//}
//
//const sf::Vector2f Player::getPosition() const
//{
//	return this->sprite.getPosition();
//}
//
//void Player::setPosition(const float x, const float y)
//{
//	this->sprite.setPosition(x, y);
//}
//
//
//void Player::animationTimer()
//{
//	this->Timer.restart();
//	this->aSwitch = true;
//}
//
//
//void Player::updateMovement()
//{
//	
//	this->vel.x = 0.0f;
//	sf::Vector2f pos = this->sprite.getPosition();
//	float maxJump = 80.f;
//	this->state = ANIMATION_STATE::IDLE;
//
//
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) { //Left
//		this->state = ANIMATION_STATE::LEFT;
//		float tmp = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ? this->acc * 1.5 : this->acc;
//		this->vel.x -= tmp;
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) { //Right
//		this->state = ANIMATION_STATE::RIGHT;
//		float tmp = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ? this->acc * 1.5 : this->acc;
//		this->vel.x += tmp;
//	}
//
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && this->canJump) { //Up
//		
//		this->canJump = false;
//		this->isJumping = true;
//		this->vel.y = -sqrtf(2.0f * 981.0f * this->jumpHeight);
//	}
//
//	if (this->isJumping) {
//		this->state = ANIMATION_STATE::FALL;
//		this->vel.y += 981.0f * deltaTime;
//	}
//
//	if (this->isJumping && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
//		this->state = ANIMATION_STATE::JUMPRIGHT;
//		this->vel.y += 981.0f * deltaTime;
//	}
//
//	if (this->isJumping && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
//		this->state = ANIMATION_STATE::JUMPLEFT;
//		this->vel.y += 981.0f * deltaTime;
//	}
//
//	if (pos.y > 300.0f) {
//		this->canJump = true;
//		this->isJumping = false;
//		this->vel.y = 0.0f;
//		this->setPosition(pos.x, 300);
//	}
//
//	this->sprite.move(this->vel * deltaTime);
//	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) { //Down
//	//	this->sprite.move(0.f, 1.f);
//	//	this->state = ANIMATION_STATE::FALL;
//	//}
//}
//
//void Player::updateAnimation()
//{
//	if (this->state == ANIMATION_STATE::IDLE) {//Idle animation
//		this->Frame.top = 0.0f;
//		if (this->Timer.getElapsedTime().asSeconds() >= 0.32f || this->getAnimation()) {
//			this->Frame.left += 32.f;
//			if (this->Frame.left >= 96.f) {
//				this->Frame.left = 0;
//			}
//
//			this->Timer.restart();
//			this->sprite.setTextureRect(this->Frame);
//		}
//	}
//	else if (this->state == ANIMATION_STATE::RIGHT) {
//		this->Frame.top = 64.f;
//		if (this->Timer.getElapsedTime().asSeconds() >= 0.18f || this->getAnimation()) {
//			this->Frame.left += 32.f;
//			if (this->Frame.left >= 160.f) {
//				this->Frame.left = 0;
//			}
//
//			this->Timer.restart();
//			this->sprite.setTextureRect(this->Frame);
//		}
//		this->sprite.setScale(2.0f, 2.0f);
//		//this->sprite.setOrigin(16.f, 0.f);
//	}
//	else if (this->state == ANIMATION_STATE::LEFT) {
//		this->Frame.top = 64.f;
//		if (this->Timer.getElapsedTime().asSeconds() >= 0.18f || this->getAnimation()) {
//			this->Frame.left += 32.f;
//			if (this->Frame.left >= 160.f) {
//				this->Frame.left = 0;
//			}
//
//			this->Timer.restart();
//			this->sprite.setTextureRect(this->Frame);
//		}
//		this->sprite.setScale(-2.0f, 2.0f);
//		//this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2.f, 0.f);
//	}
//	else if (this->state == ANIMATION_STATE::JUMPRIGHT) {
//		this->Frame.top = 192.f;
//		if (this->Timer.getElapsedTime().asSeconds() >= 0.3f || this->getAnimation()) {
//			this->Frame.left += 32.f;
//			if (this->Frame.left >= 64.f) {
//				this->Frame.left = 0;
//			}
//
//			this->Timer.restart();
//			this->sprite.setTextureRect(this->Frame);
//		}
//		this->sprite.setScale(2.0f, 2.0f);
//		//this->sprite.setOrigin(0.f, 0.f);
//	}
//	else if (this->state == ANIMATION_STATE::JUMPLEFT) {
//		this->Frame.top = 192.f;
//		if (this->Timer.getElapsedTime().asSeconds() >= 0.3f || this->getAnimation()) {
//			this->Frame.left += 32.f;
//			if (this->Frame.left >= 64.f) {
//				this->Frame.left = 0;
//			}
//
//			this->Timer.restart();
//			this->sprite.setTextureRect(this->Frame);
//		}
//		this->sprite.setScale(-2.0f, 2.0f);
//		//this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2.f, 0.f);
//	}
//	else if (this->state == ANIMATION_STATE::FALL) {
//	this->Frame.top = 160.f;
//	if (this->Timer.getElapsedTime().asSeconds() >= 0.5f) {
//		this->Frame.left += 32.f;
//		if (this->Frame.left >= 64.f) {
//			this->Frame.left = 0;
//		}
//		this->Timer.restart();
//		this->sprite.setTextureRect(this->Frame);
//	}
//	//this->sprite.setScale(2.0f, 2.0f);
//	//this->sprite.setOrigin(0.f, 0.f);
//	}
//	else {
//		this->Timer.restart();
//	}
//}
//
//void Player::update()
//{
//	this->updateMovement();
//	this->updateAnimation();
//}
//
//void Player::render(sf::RenderTarget& target)
//{
//	target.draw(this->sprite);
//}
